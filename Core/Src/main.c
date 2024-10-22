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
#include "cmsis_os.h"

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
#define YELLOW_LIGHT_DURATION	500
#define RED_LIGHT_DURATION		6000
#define GREEN_LED_PIN			GPIO_PIN_11
#define YELLOW_LED_PIN			GPIO_PIN_12
#define RED_LED_PIN				GPIO_PIN_15
#define LED_GPIO				GPIOA
#define MANUAL_MODE_PIN			GPIO_PIN_13
#define RED_MODE_PIN			GPIO_PIN_14
#define GREEN_MODE_PIN			GPIO_PIN_15
#define MANUAL_MODE_PORT		GPIOC
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* Definitions for defaultTask */

/* USER CODE BEGIN PV */
uint8_t seconds = 0;
TrafficLightState_t currentState = GREEN;
TaskHandle_t xTrafficLight, xTrafficTimer;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */
void vManualModeTask(void *pvParameters);
void vTrafficMultiplexTimer(void *pvParameters);
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
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  LED_voidInit(LED_GPIO, GREEN_LED_PIN);
  LED_voidInit(LED_GPIO, YELLOW_LED_PIN);
  LED_voidInit(LED_GPIO, RED_LED_PIN);
  SSD_voidInit();

  xTaskCreate(vTrafficMultiplexTimer, "Traffic Multiplex", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
  xTaskCreate(vTrafficLightTask, "Traffic Light", configMINIMAL_STACK_SIZE, NULL, 2, xTrafficLight);
  xTaskCreate(vTrafficTimer, "Traffic Timer", configMINIMAL_STACK_SIZE, NULL, 1, xTrafficTimer);
  xTaskCreate(vManualModeTask, "Manual Control", configMINIMAL_STACK_SIZE, NULL, 4, NULL);

  vTaskStartScheduler();
  /* USER CODE END 2 */

  /* Init scheduler */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */

  /* We should never get here as control is now taken by the scheduler */

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

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void vTrafficMultiplexTimer(void *pvParameters){
	while(1){
		SSD_voidDisplayMultiplexedNumber(seconds);
		vTaskDelay(pdMS_TO_TICKS(10));
	}

}
void vTrafficTimer(void *pvParameters){
	while (1){

		seconds++;
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}


void vTrafficLightTask(void *pvParameters) {
	while (1) {
		switch (currentState) {
			case GREEN:
			LED_voidOn(LED_GPIO, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
			LED_voidOff(LED_GPIO, RED_LED_PIN, LED_FORWARD_CONNECTION);
			LED_voidOff(LED_GPIO, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
			vTaskDelay(pdMS_TO_TICKS(GREEN_LIGHT_DURATION));
			currentState = RED;
			seconds = 0;
			break;

			case YELLOW:
				LED_voidOff(LED_GPIO, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOn(LED_GPIO, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
				vTaskDelay(pdMS_TO_TICKS(YELLOW_LIGHT_DURATION));
				currentState = GREEN;
				seconds = 0;
				break;

			case RED:
				LED_voidOff(LED_GPIO, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOn(LED_GPIO, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
				vTaskDelay(pdMS_TO_TICKS(RED_LIGHT_DURATION));
				currentState = YELLOW;
				seconds = 0;
				break;

			default:
				currentState = GREEN;
				seconds = 0 - 1;
				break;
		}
	}
}

void vManualModeTask(void *pvParameters){
	GPIO_PinState xMode = GPIO_PIN_RESET;
	GPIO_PinState xRed = GPIO_PIN_RESET;
	GPIO_PinState xGreen = GPIO_PIN_RESET;
	//eTaskState xTrafficTimerState;
	while(1){
		xMode	= HAL_GPIO_ReadPin(MANUAL_MODE_PORT, MANUAL_MODE_PIN);
		xRed 	= HAL_GPIO_ReadPin(MANUAL_MODE_PORT, RED_MODE_PIN);
		xGreen	= HAL_GPIO_ReadPin(MANUAL_MODE_PORT, GREEN_MODE_PIN);
		// Manual mode toggle off
		if(xMode == GPIO_PIN_SET){
			vTaskSuspend(xTrafficTimer);
			vTaskSuspend(xTrafficLight);
			if(xRed == GPIO_PIN_SET){
				LED_voidOff(LED_GPIO, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOn(LED_GPIO, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
			}
			else if(xGreen == GPIO_PIN_SET){
				LED_voidOn(LED_GPIO, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
			}
			else{
				LED_voidOff(LED_GPIO, GREEN_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, RED_LED_PIN, LED_FORWARD_CONNECTION);
				LED_voidOff(LED_GPIO, YELLOW_LED_PIN, LED_FORWARD_CONNECTION);
			}
		}
		else{
			if(eTaskGetState(xTrafficTimer) == eSuspended){
				vTaskResume(xTrafficTimer);
				vTaskResume(xTrafficLight);
			}
			else{
				//do nothing
			}

		}
		vTaskDelay(pdMS_TO_TICKS(50));
	}

}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */

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
