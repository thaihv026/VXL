/*
 * app_common.c - Vong lap he thong va lay mau ADC
 *
 * ADC1 quet 4 kenh moi 1 ms (TIM3 kich), thu tu rank trong CubeMX:
 *   1: IN8 (PB0) LUX_ADC    2: IN9 (PB1) VREF_TIA
 *   3: IN4 (PA4) VBAT       4: IN5 (PA5) ISENSE
 * DMA circular, bo dem 20 lan quet. Moi nua bo dem (10 lan quet = 10 ms)
 * duoc lay trung binh -> nhip 10 ms cua ca he thong.
 */
#include "app_common.h"
#include "app_config.h"
#include "main.h"
#include "adc.h"
#include "tim.h"

#include "lux.h"
#include "led.h"
#include "mcu.h"
#include "nguon.h"
#include "oled.h"
#include "uart.h"

#define ADC_CH_NUM          ADC_NUM_CH
#define ADC_SETS_PER_HALF   ADC_SAMPLES_PER_TICK
#define ADC_BUF_LEN         (ADC_CH_NUM * ADC_SETS_PER_HALF * 2u)   /* 80 mau */

sys_data_t g_sys;

static uint16_t        s_adc_buf[ADC_BUF_LEN];
static volatile int8_t s_ready_half = -1;   /* -1: chua co, 0: nua dau, 1: nua sau */
static float           s_vdda = VDDA_DEFAULT_V;

void app_set_vdda(float vdda)
{
    if (vdda > 2.0f && vdda < 3.6f) {
        s_vdda = vdda;
    }
}

/* Lay trung binh nua bo dem vua day, ghi vao g_sys */
static void adc_update(int8_t half)
{
    const uint16_t *p = &s_adc_buf[(uint32_t)half * ADC_CH_NUM * ADC_SETS_PER_HALF];
    uint32_t sum[ADC_CH_NUM] = {0};

    for (uint32_t s = 0; s < ADC_SETS_PER_HALF; s++) {
        for (uint32_t ch = 0; ch < ADC_CH_NUM; ch++) {
            sum[ch] += p[s * ADC_CH_NUM + ch];
        }
    }

    const float k = s_vdda / ADC_FULL_SCALE / (float)ADC_SETS_PER_HALF;
    g_sys.v_lux    = (float)sum[0] * k;
    g_sys.v_vref   = (float)sum[1] * k;
    g_sys.v_vbat   = (float)sum[2] * k;
    g_sys.v_isense = (float)sum[3] * k;
}

void app_init(void)
{
    g_sys.mode       = MODE_MEASURE;
    g_sys.setpoint   = SETPOINT_DEFAULT_LUX;
    g_sys.led_enable = false;

    nguon_init();
    mcu_init();
    lux_init();
    led_init();
    oled_init();
    uart_init();

    /* Bat lay mau: hieu chuan ADC -> DMA -> timer kich */
    HAL_ADCEx_Calibration_Start(&hadc1);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)s_adc_buf, ADC_BUF_LEN);
    HAL_TIM_Base_Start(&htim3);
}

void app_loop(void)
{
    int8_t half = s_ready_half;
    if (half < 0) {
        return;             /* chua du 10 ms */
    }
    s_ready_half = -1;

    adc_update(half);
    g_sys.tick++;

    /* 100 Hz: do, dieu phoi, dieu khien */
    lux_task_10ms();
    mcu_task_10ms();
    led_task_10ms();

    /* 10 Hz: man hinh, log */
    if (g_sys.tick % TASK_DIV_100MS == 0u) {
        oled_task_100ms();
        uart_task_100ms();
    }

    /* 1 Hz: pin */
    if (g_sys.tick % TASK_DIV_1S == 0u) {
        nguon_task_1s();
    }
}

/* Callback cua HAL. KHONG dinh nghia lai hai ham nay o file khac. */
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC1) {
        s_ready_half = 0;
    }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc->Instance == ADC1) {
        s_ready_half = 1;
    }
}
