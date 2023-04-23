/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define S0_VALID   GPIO_PIN_RESET
#define S1_VALID   GPIO_PIN_SET
#define S2_VALID   GPIO_PIN_SET
#define S3_VALID   GPIO_PIN_RESET
#define S4_VALID   GPIO_PIN_RESET

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	uint8_t B1 = 0;
	uint8_t B2 = 0;
	uint8_t B3 = 0;
	uint8_t B4 = 0;
	uint8_t B5T = 0;
	uint8_t B5P = 0;
	uint8_t S0 = 0;
	uint8_t S1 = 0;
	uint8_t S2 = 0;
	uint8_t S3 = 0;
	uint8_t S4 = 0;
	uint8_t sysState = 0;
	uint32_t Delay_cnt=0;
	HAL_GPIO_WritePin(D1_GPIO_Port,D1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(D2_GPIO_Port,D2_Pin,GPIO_PIN_SET);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		B1 = HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin);
		B2 = HAL_GPIO_ReadPin(B2_GPIO_Port,B2_Pin);
		B3 = HAL_GPIO_ReadPin(B3_GPIO_Port,B3_Pin);
		B4 = HAL_GPIO_ReadPin(B4_GPIO_Port,B4_Pin);
		B5T = HAL_GPIO_ReadPin(B5Trai_GPIO_Port,B5Trai_Pin);
		S0 = HAL_GPIO_ReadPin(S0_GPIO_Port,S0_Pin);
		S1 = HAL_GPIO_ReadPin(S1_GPIO_Port,S1_Pin);
		S2 = HAL_GPIO_ReadPin(S2_GPIO_Port,S2_Pin);
		S3 = HAL_GPIO_ReadPin(S3_GPIO_Port,S3_Pin);
		S4 = HAL_GPIO_ReadPin(S4_GPIO_Port,S4_Pin);
			
		if ((sysState == 0)&&(B1==GPIO_PIN_RESET))
			sysState=1;
		else if ((sysState == 1)&&(B2==GPIO_PIN_RESET))
			sysState = 2;
		else if ((sysState == 2) || sysState == 0 &&(B3==GPIO_PIN_RESET))
			sysState = 3;
		else if ((sysState == 3)&&(B3==GPIO_PIN_SET))
			sysState = 0;
		else if ((sysState == 1) || sysState == 3 &&(B4==GPIO_PIN_RESET))
			sysState = 4;
		else if ((sysState == 4)&&(B3==GPIO_PIN_SET))
			sysState = 1;	


		if(sysState == 0) HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_SET);
		
		else if(sysState==1){
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_RESET);
		}
		else if(sysState == 2){
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_SET);
		}
		else if(sysState ==3){
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_RESET);	
		}
		else if(sysState ==4){
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_SET);	
		}

		// State control
		/*
		if ((sysState == 0)&&(S0!=S0_VALID))
			sysState=1;
		else if ((sysState == 1)&&(Delay_cnt==1000))
			sysState = 2;
		else if ((sysState == 2)&&(S2 != S2_VALID))
			sysState = 31;
		else if (((sysState == 2)||(sysState == 31))&&(S2 == S2_VALID))
			sysState = 32;	
		else if ((sysState == 32)&&(S4 != S4_VALID))
			sysState = 4;	
		else if ((sysState == 4)&&(S4 == S4_VALID))
			sysState = 5;	
		else if ((sysState == 5)&&(S1 != S1_VALID))
			sysState = 6;	
		else if ((sysState == 6)&&(S1 == S1_VALID))
			sysState = 7;	
		else if ((sysState == 7)&&(Delay_cnt==1000))
			sysState = 8;	
		else if ((sysState == 8)&&(S2!=S2_VALID))
			sysState = 9;	
		else if ((sysState == 9)&&(S2==S2_VALID))
			sysState = 10;	
		else if ((sysState == 10)&&(S3!=S3_VALID))
			sysState = 11;	
		else if ((sysState == 11)&&(S3==S3_VALID))
			sysState = 12;	
		else if ((sysState == 12)&&(S1!=S1_VALID))
			sysState = 13;
		else if ((sysState == 13)&&(S1==S1_VALID))
			sysState = 14;
		else if ((sysState == 14)&&(Delay_cnt==1000))
			sysState = 0;		
		
		// Output
		if (sysState==0) {
			Delay_cnt=0;
		}
		else if (sysState==1) {
			HAL_GPIO_WritePin(K1_GPIO_Port,K1_Pin,GPIO_PIN_SET);
			if (Delay_cnt<1000) {
				HAL_Delay(1);
				Delay_cnt = Delay_cnt + 1;
			}
		}
		else if (sysState==2) {

		}
		else if (sysState==31) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_SET);
		}
		else if (sysState==32) {
			HAL_GPIO_WritePin(K3_GPIO_Port,K3_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(K4_GPIO_Port,K4_Pin,GPIO_PIN_RESET);
		}		
		else if (sysState==4) {
			HAL_GPIO_WritePin(K3_GPIO_Port,K3_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(K4_GPIO_Port,K4_Pin,GPIO_PIN_RESET);
		}	
		else if (sysState==5) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_RESET);
		}				
		else if (sysState==6) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_RESET);
			Delay_cnt=0;
		}	
		else if (sysState==7) {
			HAL_GPIO_WritePin(K1_GPIO_Port,K1_Pin,GPIO_PIN_RESET);
			if (Delay_cnt<1000) {
				HAL_Delay(1);
				Delay_cnt = Delay_cnt + 1;
			}
		}	
		else if (sysState==8) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_SET);
		}
		else if (sysState==9) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_SET);
		}
		else if (sysState==10) {
			HAL_GPIO_WritePin(K3_GPIO_Port,K3_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(K4_GPIO_Port,K4_Pin,GPIO_PIN_SET);
		}	
		else if (sysState==11) {
			
		}	
		else if (sysState==12) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_RESET);
		}	
		else if (sysState==13) {
			HAL_GPIO_WritePin(K2_GPIO_Port,K2_Pin,GPIO_PIN_RESET);
			Delay_cnt=0;
		}	
		else if (sysState==14) {
			HAL_GPIO_WritePin(K1_GPIO_Port,K1_Pin,GPIO_PIN_SET);
			if (Delay_cnt<1000) {
				HAL_Delay(1);
				Delay_cnt = Delay_cnt + 1;
			}
		}				*/
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, K1_Pin|K2_Pin|K3_Pin|K4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE3 PE4 PE5
                           PE6 PE11 PE12 PE13
                           PE15 PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PC13 PC14 PC15 PC0
                           PC1 PC2 PC3 PC4
                           PC5 PC9 PC10 PC11
                           PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PH0 PH1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA8
                           PA9 PA10 PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : D1_Pin */
  GPIO_InitStruct.Pin = D1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(D1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB11
                           PB12 PB13 PB14 PB15
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : D2_Pin */
  GPIO_InitStruct.Pin = D2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(D2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : K1_Pin K2_Pin K3_Pin K4_Pin */
  GPIO_InitStruct.Pin = K1_Pin|K2_Pin|K3_Pin|K4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : B4_Pin */
  GPIO_InitStruct.Pin = B4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(B4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD10 PD12
                           PD14 PD15 PD0 PD1
                           PD2 PD3 PD4 PD5
                           PD6 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1
                          |GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : B1_Pin S0_Pin */
  GPIO_InitStruct.Pin = B1_Pin|S0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : B2_Pin B3_Pin */
  GPIO_InitStruct.Pin = B2_Pin|B3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : B5Phai_Pin */
  GPIO_InitStruct.Pin = B5Phai_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B5Phai_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B5Trai_Pin */
  GPIO_InitStruct.Pin = B5Trai_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(B5Trai_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : S4_Pin */
  GPIO_InitStruct.Pin = S4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(S4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : S3_Pin S1_Pin S2_Pin */
  GPIO_InitStruct.Pin = S3_Pin|S1_Pin|S2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
