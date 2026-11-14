/*
 * led.c - Khoi LED vong kin (NGUOI 2)
 *
 * CHUC NANG
 *   Xuat PWM -> loc RC -> nguon dong hang (op-amp + MOSFET) giu dong LED
 *   bang VSET / Rs. Bo PI chinh duty de lux do duoc bang setpoint.
 *
 * VAO
 *   g_sys.lux, g_sys.settling          (tu khoi lux)
 *   g_sys.setpoint, g_sys.led_enable   (tu khoi mcu)
 *   g_sys.v_isense (V) = dong LED * 1 ohm, 0 .. 0.2 V
 *
 * RA
 *   PWM_LED (PA2, TIM2_CH3): 70.3 kHz, CCR 0 .. 1024
 *     VSET = 0.359 * duty (V), I_LED = VSET / 1 ohm
 *     gioi han duty <= 0.557 (~200 mA)
 *   g_sys.duty, g_sys.led_mA, g_sys.led_status
 *
 * YEU CAU
 *   - g_sys.led_enable = false -> duty = 0
 *   - g_sys.settling = true    -> giu nguyen duty
 */
#include "led.h"
#include "app_common.h"
#include "app_config.h"
#include "main.h"

void led_init(void)
{
    /* TODO (nguoi 2) */
}

void led_task_10ms(void)
{
    /* TODO (nguoi 2) */
}
