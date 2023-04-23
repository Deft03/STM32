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
#include "stm32f2xx_hal.h"

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
#define D1_Pin GPIO_PIN_7
#define D1_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOB
#define K1_Pin GPIO_PIN_7
#define K1_GPIO_Port GPIOE
#define K2_Pin GPIO_PIN_8
#define K2_GPIO_Port GPIOE
#define K3_Pin GPIO_PIN_9
#define K3_GPIO_Port GPIOE
#define K4_Pin GPIO_PIN_10
#define K4_GPIO_Port GPIOE
#define B4_Pin GPIO_PIN_14
#define B4_GPIO_Port GPIOE
#define B1_Pin GPIO_PIN_11
#define B1_GPIO_Port GPIOD
#define S0_Pin GPIO_PIN_13
#define S0_GPIO_Port GPIOD
#define B2_Pin GPIO_PIN_6
#define B2_GPIO_Port GPIOC
#define B3_Pin GPIO_PIN_7
#define B3_GPIO_Port GPIOC
#define B5Phai_Pin GPIO_PIN_8
#define B5Phai_GPIO_Port GPIOC
#define B5Trai_Pin GPIO_PIN_15
#define B5Trai_GPIO_Port GPIOA
#define S4_Pin GPIO_PIN_7
#define S4_GPIO_Port GPIOD
#define S3_Pin GPIO_PIN_3
#define S3_GPIO_Port GPIOB
#define S1_Pin GPIO_PIN_4
#define S1_GPIO_Port GPIOB
#define S2_Pin GPIO_PIN_5
#define S2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
