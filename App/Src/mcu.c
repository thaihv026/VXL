/*
 * mcu.c - Khoi dieu phoi: che do, nut bam, setpoint (NGUOI 3)
 *
 * CHUC NANG
 *   Doc 5 nut, chuyen che do (DO / DIEU KHIEN / HIEU CHUAN / PIN YEU),
 *   chinh setpoint, cho phep hoac tat LED, HOLD so hien thi,
 *   luu cau hinh vao flash, nhay LED trang thai.
 *
 * VAO
 *   Nut (0 = bam): PB12 UP, PB13 DOWN, PB14 OK, PB15 BACK, PA8 HOLD
 *   g_sys.batt_low (tu khoi nguon), cac truong khac cua g_sys
 *
 * RA
 *   LED_STATUS (PC13, sang khi keo xuong 0)
 *   g_sys.mode, g_sys.setpoint, g_sys.led_enable, g_sys.hold
 *
 * CHUYEN CHE DO (de xuat)
 *   DO --OK--> DIEU KHIEN --BACK--> DO
 *   DO --giu OK 2 s--> HIEU CHUAN --OK luu / BACK huy--> DO
 *   DIEU KHIEN --pin yeu--> PIN YEU (LED tat, chi do)
 */
#include "mcu.h"
#include "app_common.h"
#include "main.h"

void mcu_init(void)
{
    /* TODO (nguoi 3) */
}

void mcu_task_10ms(void)
{
    /* TODO (nguoi 3) */
}
