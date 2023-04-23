/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define LED_E_Pin GPIO_PIN_2
#define LED_E_GPIO_Port GPIOE
#define LCDD4_Pin GPIO_PIN_0
#define LCDD4_GPIO_Port GPIOD
#define LCDD5_Pin GPIO_PIN_1
#define LCDD5_GPIO_Port GPIOD
#define LCDD6_Pin GPIO_PIN_2
#define LCDD6_GPIO_Port GPIOD
#define LCDD7_Pin GPIO_PIN_3
#define LCDD7_GPIO_Port GPIOD
#define LCDLED_Pin GPIO_PIN_4
#define LCDLED_GPIO_Port GPIOD
#define LCDE_Pin GPIO_PIN_5
#define LCDE_GPIO_Port GPIOD
#define LCDRW_Pin GPIO_PIN_6
#define LCDRW_GPIO_Port GPIOD
#define LCDRS_Pin GPIO_PIN_7
#define LCDRS_GPIO_Port GPIOD
#define BT_CLK_Pin GPIO_PIN_3
#define BT_CLK_GPIO_Port GPIOB
#define BT_SERIAL_Pin GPIO_PIN_4
#define BT_SERIAL_GPIO_Port GPIOB
#define LED_DATA_Pin GPIO_PIN_5
#define LED_DATA_GPIO_Port GPIOB
#define LED_LAT_Pin GPIO_PIN_0
#define LED_LAT_GPIO_Port GPIOE
#define BT_LOAD_Pin GPIO_PIN_1
#define BT_LOAD_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
