/*
 * app_common.h - Vong lap he thong va du lieu chung
 * May do lux TIA tu chuyen thang + LED vong kin, STM32F103C8T6
 *
 * VONG LAP HE THONG
 *   1 kHz  : ADC quet 4 kenh (phan cung TIM3 + DMA)
 *   100 Hz : trung binh 10 mau -> g_sys, roi goi
 *              lux_task_10ms()    khoi do lux
 *              mcu_task_10ms()    che do, nut, setpoint
 *              led_task_10ms()    LED vong kin
 *   10 Hz  :   oled_task_100ms()  man hinh
 *              uart_task_100ms()  log, lenh tu may tinh
 *   1 Hz   :   nguon_task_1s()    pin
 *
 * QUY TAC
 *   - Moi khoi chi cong khai xxx_init() va mot ham xxx_task_...().
 *     Ben trong khoi, nguoi phu trach tu tao them ham, file.
 *   - Cac khoi trao doi qua bien chung g_sys, khong goi ham cua nhau.
 *   - Moi truong trong g_sys chi DUNG MOT khoi duoc ghi (xem ghi chu).
 *   - Moi ham task phai chay xong nhanh, khong dung HAL_Delay().
 *     Tong thoi gian cac task trong mot nhip phai duoi 10 ms, neu khong
 *     se mat cua so du lieu ADC. Rieng OLED: gui ca khung hinh qua I2C
 *     mat ~25 ms -> dung HAL_I2C_..._DMA hoac moi lan chi gui mot phan.
 *   - Chi nguoi 3 sua app_common.c/.h va file .ioc.
 *
 * NGOAI VI THUOC VE AI
 *   ADC1, DMA1_Ch1, TIM3         : app_common.c
 *   PB10, PB11 (chon thang)      : lux
 *   TIM2_CH3 / PA2 (PWM LED)     : led
 *   Nut PB12-PB15, PA8; PC13     : mcu
 *   I2C1 (PB6, PB7)              : oled
 *   USART1 (PA9, PA10), USB      : uart
 */
#ifndef APP_COMMON_H
#define APP_COMMON_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    MODE_MEASURE = 0,   /* chi do, LED tat */
    MODE_CONTROL,       /* dieu khien LED vong kin */
    MODE_CALIB,         /* hieu chuan */
    MODE_LOW_BATT       /* pin yeu: chi do, LED tat */
} sys_mode_t;

typedef enum {
    LED_ST_OK = 0,      /* dang dat setpoint */
    LED_ST_SAT_HIGH,    /* LED het co ma van thieu sang */
    LED_ST_SAT_LOW      /* LED da tat ma van thua sang (do moi truong) */
} led_status_t;

/* Du lieu chung. [ai ghi]: chi khoi do duoc ghi, cac khoi khac chi doc. */
typedef struct {
    /* [app_common] trung binh 10 ms cua 4 kenh ADC, don vi V */
    float        v_lux;       /* PB0  LUX_ADC    0.2 .. 3.0 V      */
    float        v_vref;      /* PB1  VREF_TIA   ~0.2 V            */
    float        v_vbat;      /* PA4  VBAT_SENSE = VSYS / 3        */
    float        v_isense;    /* PA5  ISENSE     = I_LED * 1 ohm   */
    uint32_t     tick;        /* so nhip 10 ms tu luc khoi dong    */

    /* [lux] */
    float        lux;         /* lux da hieu chuan */
    uint8_t      range;       /* thang 0..3 */
    bool         settling;    /* true ngay sau khi doi thang */
    bool         overrange;   /* vuot thang lon nhat */

    /* [mcu] */
    sys_mode_t   mode;
    float        setpoint;    /* lux */
    bool         led_enable;  /* cho phep khoi LED bat LED */
    bool         hold;        /* nut HOLD: dong bang so hien thi */

    /* [led] */
    float        duty;        /* 0 .. 0.557 */
    float        led_mA;      /* dong LED */
    led_status_t led_status;

    /* [nguon] */
    float        vsys;        /* V */
    bool         batt_low;
} sys_data_t;

extern sys_data_t g_sys;

/* Goi tu main.c */
void app_init(void);    /* USER CODE BEGIN 2 */
void app_loop(void);    /* USER CODE BEGIN 3, ben trong while (1) */

/* VDDA dung de quy doi ADC, mac dinh 3.30 V (do bang dong ho) */
void app_set_vdda(float vdda);

#endif /* APP_COMMON_H */
