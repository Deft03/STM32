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
#define LCDRW_Pin GPIO_PIN_2
#define LCDRW_GPIO_Port GPIOB
#define LCDD2_Pin GPIO_PIN_10
#define LCDD2_GPIO_Port GPIOB
#define LCDD3_Pin GPIO_PIN_11
#define LCDD3_GPIO_Port GPIOB
#define LCDD4_Pin GPIO_PIN_12
#define LCDD4_GPIO_Port GPIOB
#define LCDD5_Pin GPIO_PIN_13
#define LCDD5_GPIO_Port GPIOB
#define LCDD6_Pin GPIO_PIN_14
#define LCDD6_GPIO_Port GPIOB
#define LCDD7_Pin GPIO_PIN_15
#define LCDD7_GPIO_Port GPIOB
#define LCDRS_Pin GPIO_PIN_6
#define LCDRS_GPIO_Port GPIOB
#define LCDEN_Pin GPIO_PIN_7
#define LCDEN_GPIO_Port GPIOB
#define LCDD0_Pin GPIO_PIN_8
#define LCDD0_GPIO_Port GPIOB
#define LCDD1_Pin GPIO_PIN_9
#define LCDD1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
