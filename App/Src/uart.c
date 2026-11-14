/*
 * uart.c - Giao tiep may tinh (NGUOI 3)
 *
 * CHUC NANG
 *   Gui log du lieu len may tinh (khoang 10 lan/giay) de ve do thi,
 *   nhan lenh tu may tinh de thu nghiem va hieu chuan.
 *   Giai doan sau co the chuyen sang USB CDC.
 *
 * VAO
 *   USART1 RX (PA10), 115200 8N1
 *   Doc g_sys de gui log
 *
 * RA
 *   USART1 TX (PA9)
 *   Lenh tu may tinh duoc chuyen thanh thay doi g_sys theo dung chu so huu
 *   cua truong do (vd. setpoint thuoc khoi mcu)
 */
#include "uart.h"
#include "app_common.h"
#include "main.h"

void uart_init(void)
{
    /* TODO (nguoi 3) */
}

void uart_task_100ms(void)
{
    /* TODO (nguoi 3) */
}
