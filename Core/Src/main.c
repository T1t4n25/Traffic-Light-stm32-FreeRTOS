/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include <LED_interface.h>
#include <SSD_interface.h>
#include <FreeRTOS.h>
#include <task.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {
	GREEN = 0,
	YELLOW,
	RED
} TrafficLightState_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define GREEN_LIGHT_DURATION	6000
#define YELLOW_LIGHT_DURATION	2000
#define RED_LIGHT_DURATION		6000
#define GREEN_LED_PIN			GPIO_PIN_3
#define YELLOW_LED_PIN			GPIO_PIN_4
#define RED_LED_PIN				GPIO_PIN_5
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

TrafficLightState_t currentState = GREEN;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void vtaskempty(void *pvParameters);
void vTrafficLightTask(void *pvParameters);
void vTrafficTimer(void *pvParameters);
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
  /* USER CODE BEGIN 2 */
  LED_voidInit(GPIOB, GREEN_LED_PIN);
  LED_voidInit(GPIOB, YELLOW_LED_PIN);
  LED_voidInit(GPIOB, RED_LED_PIN);
  SSD_voidInit();

  //xTaskCreate(vtaskempty, "Traffic Light", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(vTrafficLightTask, "Traffic Light", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(vTrafficTimer, "Traffic Timer", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  vTaskStartScheduler();
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

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

/* USER CODE BEGIN 4 */


void vTrafficTimer(void *pvParameters){
	uint8_t max = 6;
	uint8_t seconds = 0;
	while (1){

		switch (currentState) {
			case GREEN:
				max = GREEN_LIGHT_DURATION/1000;
				if (seconds < max)
				{
					SSD_voidDisplayNumber(seconds, SSD_A);
					seconds++;
					vTaskDelay(pdMS_TO_TICKS(1000));
				}
				else{
					seconds = 0;
				}
				break;

			case YELLOW:
				max = YELLOW_LIGHT_DURATION/1000;
				if (seconds < max)
				{
					SSD_voidDisplayNumber(seconds, SSD_A);
					seconds++;
					vTaskDelay(pdMS_TO_TICKS(1000));
				}
				else{
					seconds = 0;
				}
				break;

			case RED:
				max = RED_LIGHT_DURATION/1000;
				if (seconds < max)
				{
					SSD_voidDisplayNumber(seconds, SSD_A);
					seconds++;
					vTaskDelay(pdMS_TO_TICKS(1000));
				}
				else{
					seconds = 0;
				}
				break;

			default:
				seconds = 0;
				break;
		}
	}
}


void vTrafficLightTask(void *pvParameters) {
	while (1) {
		switch (currentState) {
			case GREEN:
			LED_voidOn(GPIOA, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
			LED_voidOff(GPIOA, RED_LED_PIN, LED_FORWARD_CONNECTION);
			LED_voidOff(GPIOA, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
			vTaskDelay(pdMS_TO_TICKS(GREEN_LIGHT_DURATION));
			currentState = RED;

			break;

			case YELLOW:
				LED_voidOff(GPIOA, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(GPIOA, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOn(GPIOA, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
				vTaskDelay(pdMS_TO_TICKS(YELLOW_LIGHT_DURATION));
				currentState = GREEN;

				break;

			case RED:
				LED_voidOff(GPIOA, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOn(GPIOA, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(GPIOA, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
				vTaskDelay(pdMS_TO_TICKS(RED_LIGHT_DURATION));
				currentState = YELLOW;

				break;

			default:
				currentState = GREEN;

				break;
		}
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM2) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
