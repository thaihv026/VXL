/*
 * nguon.c - Khoi nguon: theo doi pin (NGUOI 3)
 *
 * CHUC NANG (phan cung)
 *   4xAA (4.2 .. 6.4 V) hoac USB 5 V -> 2 diode Schottky -> VSYS
 *   VSYS -> LDO 3.3 V -> 3V3D (MCU, OLED) -> ferrite -> 3V3A (TIA, mux, op-amp, VDDA)
 *
 * CHUC NANG (firmware)
 *   Tinh VSYS tu cau chia, bao pin yeu (co do tre de khong nhay qua lai).
 *
 * VAO
 *   g_sys.v_vbat (V) = VSYS / 3, khoang 1.3 .. 2.0 V
 *
 * RA
 *   g_sys.vsys, g_sys.batt_low
 *   De xuat: pin yeu khi VSYS < 4.3 V, het yeu khi VSYS > 4.5 V
 */
#include "nguon.h"
#include "app_common.h"
#include "app_config.h"
#include "main.h"

void nguon_init(void)
{
    /* TODO (nguoi 3) */
}

void nguon_task_1s(void)
{
    /* TODO (nguoi 3) */
}
