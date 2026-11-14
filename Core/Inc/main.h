/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_STATUS_Pin GPIO_PIN_13
#define LED_STATUS_GPIO_Port GPIOC
#define PMW_LED_Pin GPIO_PIN_2
#define PMW_LED_GPIO_Port GPIOA
#define VBAT_SENSE_Pin GPIO_PIN_4
#define VBAT_SENSE_GPIO_Port GPIOA
#define ISENSE_Pin GPIO_PIN_5
#define ISENSE_GPIO_Port GPIOA
#define LUX_ADC_Pin GPIO_PIN_0
#define LUX_ADC_GPIO_Port GPIOB
#define VREF_TIA_Pin GPIO_PIN_1
#define VREF_TIA_GPIO_Port GPIOB
#define MUX_S0_Pin GPIO_PIN_10
#define MUX_S0_GPIO_Port GPIOB
#define MUX_S1_Pin GPIO_PIN_11
#define MUX_S1_GPIO_Port GPIOB
#define BTN_DOWN_Pin GPIO_PIN_12
#define BTN_DOWN_GPIO_Port GPIOB
#define BTN_UP_Pin GPIO_PIN_13
#define BTN_UP_GPIO_Port GPIOB
#define BTN_BACK_Pin GPIO_PIN_14
#define BTN_BACK_GPIO_Port GPIOB
#define BTN_OK_Pin GPIO_PIN_15
#define BTN_OK_GPIO_Port GPIOB
#define BTN_HOLD_Pin GPIO_PIN_8
#define BTN_HOLD_GPIO_Port GPIOA
#define UART_TX_Pin GPIO_PIN_9
#define UART_TX_GPIO_Port GPIOA
#define UART_RX_Pin GPIO_PIN_10
#define UART_RX_GPIO_Port GPIOA
#define OLED_SCL_Pin GPIO_PIN_6
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_7
#define OLED_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
