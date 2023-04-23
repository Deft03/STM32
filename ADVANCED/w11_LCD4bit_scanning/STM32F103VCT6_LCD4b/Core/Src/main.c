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
void InitHD44780(void){
	HAL_Delay(15);
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDRW_GPIO_Port, LCDRW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	
	HAL_Delay(5);
	//<D7> <D6> <D5> <D4> = 0011
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 0011
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 0010
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
		//<D7> <D6> <D5> <D4> = 0010

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = N*** = 1***
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 0000
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 1000
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> `	= 0000
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);


	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 0001
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 0000
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	//<D7> <D6> <D5> <D4> = 0 0 I/D S =>> 0 1 1 0
	//S: Shifts the entire display either to the right (I/D = 0) or to the left (I/D = 1) when S is 1.
	// I/D =1 (INCREMENT) ; I/D = 0(DECREMENT) 
	
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	// LED Initilize ends
	
	// Display control 0B 0000 1 D=1 C=1 B=1
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(LCDLED_GPIO_Port, LCDLED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_SET);
}
void LCD_put(uint8_t ch){
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_SET);

	
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, ch&0x80);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, ch&0x40);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, ch&0x20);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, ch&0x10);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, ch&0x08);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, ch&0x04);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, ch&0x02);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, ch&0x01);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	
	}
void LCD_cmd(uint8_t ch){
	HAL_GPIO_WritePin(LCDRS_GPIO_Port, LCDRS_Pin, GPIO_PIN_RESET);

	
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, ch&0x80);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, ch&0x40);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, ch&0x20);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, ch&0x10);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, ch&0x08);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, ch&0x04);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, ch&0x02);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, ch&0x01);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	
	}
void LCD_sprintf(uint8_t *s){
	int i=0;
	while(*(s+i) != 0){
		LCD_put(*(s+i));
		i++;
	}
}
void LCD_CGRAM(uint8_t *arr, uint8_t pos){
	for(int i=0; i<7; i++){
		LCD_cmd(0x40 + (pos<<3) + i);
		LCD_put(*(arr+i));
	}
	
}
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
	InitHD44780();
  /* USER CODE BEGIN 2 */
	//<D7> <D6> <D5> <D4> = 0011
	
	
	// Display control U 0101 0101
	/*
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port, LCDD7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD6_GPIO_Port, LCDD6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD5_GPIO_Port, LCDD5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD4_GPIO_Port, LCDD4_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port, LCDE_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	*/
	//LCD_sprintf("HCMUTE");
	
	//CGRAM ADDRESS

/////
	LCD_cmd(0x40+ (1<<3) + 0);
	LCD_put(0);
	LCD_cmd(0x40+ (1<<3) + 1);
	LCD_put(10);
	LCD_cmd(0x40+ (1<<3) + 2);
	LCD_put(0);
	LCD_cmd(0x40+ (1<<3) + 3);
	LCD_put(17);
	LCD_cmd(0x40+ (1<<3) + 4);
	LCD_put(14);
	LCD_cmd(0x40+ (1<<3) + 5);
	LCD_put(0);
	LCD_cmd(0x40+ (1<<3) + 6);
	LCD_put(0);
	///
	const uint8_t CHAR0[] = {0,10,31,31,14,4,0};
	const uint8_t CHAR1[] = {0,10,0,17,14,0,0};
	const uint8_t CHAR2[] = {16,24,28,30,28,24,16,0};


	
	LCD_CGRAM((uint8_t *)CHAR0, 0);
	LCD_CGRAM((uint8_t *)CHAR1, 1);
	LCD_CGRAM((uint8_t *)CHAR2, 2);

	LCD_cmd(0x80 + 0x00);
	LCD_put(2);
	LCD_put(1);
	LCD_put(1);
	LCD_put(1);
	LCD_put(1);
	LCD_put(1);
	LCD_put(2);
	///
	LCD_cmd(0x80 + 0x40); // set second line of lcd
	LCD_put(0);
	LCD_sprintf((uint8_t *)"HCMUTE");
	LCD_put(0);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE3 PE4 PE5
                           PE6 PE7 PE8 PE9
                           PE10 PE11 PE12 PE13
                           PE14 PE15 PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PC13 PC14 PC15 PC0
                           PC1 PC2 PC3 PC4
                           PC5 PC6 PC7 PC8
                           PC9 PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7
                           PA8 PA9 PA10 PA11
                           PA12 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB15 PB3 PB4 PB5
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD10 PD11
                           PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PD0 PD1 PD2 PD3
                           PD4 PD5 PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

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
