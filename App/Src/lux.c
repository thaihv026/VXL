/*
 * lux.c - Khoi do lux tu chuyen thang (NGUOI 1)
 *
 * CHUC NANG
 *   Bien anh sang thanh dien ap (photodiode BPW34 + TIA MCP6001), tu chon
 *   1 trong 4 thang Rf qua mux 74HC4052 (noi Kelvin) de tin hieu luon nam
 *   trong dai ADC, roi tinh ra gia tri lux da hieu chuan.
 *
 * VAO
 *   g_sys.v_lux   (V)  dien ap tai dau Rf, 0.2 .. 3.0 V (thang 3 toi da 2.8 V)
 *   g_sys.v_vref  (V)  ~0.2 V
 *
 * RA
 *   Chan RANGE_S0 (PB10), RANGE_S1 (PB11): chon thang = S1*2 + S0
 *   g_sys.lux, g_sys.range, g_sys.settling, g_sys.overrange
 *
 *   Thang  S1 S0   Rf      Lux toan thang (uoc luong)
 *     0     0  0   1 M     ~60
 *     1     0  1   100 k   ~600
 *     2     1  0   10 k    ~6000
 *     3     1  1   1 k     ~50000
 */
#include "lux.h"
#include "app_common.h"
#include "app_config.h"
#include "main.h"

void lux_init(void)
{
    /* TODO (nguoi 1) */
}

void lux_task_10ms(void)
{
    /* TODO (nguoi 1) */
}
