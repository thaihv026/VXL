/*
 * app_config.h - Thong so phan cung va thoi gian dung chung
 *
 * CHI dat o day:
 *   - Thong so phu thuoc vao mach (gia tri linh kien, ty le chia, gioi han)
 *   - Thong so nhieu khoi cung dung (nhip chay, cau hinh ADC)
 * KHONG dat o day:
 *   - Tham so chinh rieng cua mot khoi (nguong chuyen thang, nguong pin yeu,
 *     thoi gian chong doi...) -> #define trong file .c cua khoi do
 *   - Gia tri hieu chuan (offset, gain, Kp, Ki) -> do tren mach that,
 *     luu vao flash, khong phai hang so
 *
 */
#ifndef APP_CONFIG_H
#define APP_CONFIG_H

/* ===================== Nhip chay ===================== */
#define TICK_MS                 10u     /* nhip chinh 10 ms (100 Hz) */
#define TASK_DIV_100MS          10u     /* 10 nhip = 100 ms (10 Hz) */
#define TASK_DIV_1S             100u    /* 100 nhip = 1 s (1 Hz) */

/* ===================== ADC ===================== */
/* TIM3 kich ADC 1 kHz (PSC 71, ARR 999). Thu tu rank phai khop CubeMX. */
#define ADC_SAMPLE_HZ           1000u
#define ADC_NUM_CH              4u      /* rank 1 IN8 lux, 2 IN9 vref, 3 IN4 vbat, 4 IN5 isense */
#define ADC_SAMPLES_PER_TICK    (ADC_SAMPLE_HZ * TICK_MS / 1000u)   /* = 10 */
#define ADC_FULL_SCALE          4095.0f
#define VDDA_DEFAULT_V          3.30f   /* do lai bang dong ho, luu vao flash */

/* ===================== Khoi do lux ===================== */
#define NUM_RANGES              4u
#define RF_RANGE0_OHM           1.0e6f
#define RF_RANGE1_OHM           1.0e5f
#define RF_RANGE2_OHM           1.0e4f
#define RF_RANGE3_OHM           1.0e3f
#define RF_OHM_LIST             { RF_RANGE0_OHM, RF_RANGE1_OHM, RF_RANGE2_OHM, RF_RANGE3_OHM }

#define VREF_TIA_NOMINAL_V      0.206f  /* cau chia 30k / 2k tu 3.3 V */
#define V_LUX_MAX_V             3.0f    /* dau ra TIA toi da, thang 0..2 */
#define V_LUX_MAX_RANGE3_V      2.8f    /* thang 3: chua cho op-amp bu Ron cua mux */

/* Do nhay photodiode, chi dung de tinh gain mac dinh truoc khi hieu chuan.
 * BPW34 ~50 nA/lux voi nguon sang chuan A; voi LED trang thap hon. */
#define PD_SENSITIVITY_A_PER_LUX 50.0e-9f

/* ===================== Khoi LED ===================== */
#define PWM_PERIOD              1024u   /* TIM2 ARR = 1023 -> 72 MHz / 1024 = 70.3 kHz */
#define VSET_PER_DUTY_V         0.359f  /* 3.3 V * 3.3k / (27k + 3.3k) */
#define RS_OHM                  1.0f    /* dien tro sense */
#define LED_MAX_MA              200.0f  /* gioi han dong LED */
#define DUTY_MAX                ((LED_MAX_MA / 1000.0f) * RS_OHM / VSET_PER_DUTY_V)  /* ~0.557 */

/* ===================== Nguon ===================== */
#define VBAT_DIVIDER            3.0f    /* VSYS = 3 * VBAT_SENSE (200k / 100k) */

/* ===================== He thong ===================== */
#define SETPOINT_DEFAULT_LUX    300.0f

#endif /* APP_CONFIG_H */
