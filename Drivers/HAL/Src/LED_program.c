/*
 * LED_program.c
 *
 *  Created on: 26/09/2024
 *      Author: Zeyad Hemeda
 */



/* MCAL */
#include "main.h"

/* HAL */
#include "LED_interface.h"


void LED_voidInit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	// Step 1: Enable the GPIO clock for the corresponding port using switch
	   switch ((uint32_t)GPIOx) {
	        case (uint32_t)GPIOA:
	            __HAL_RCC_GPIOA_CLK_ENABLE();  // Enable the clock for GPIO Port A
	            break;
	        case (uint32_t)GPIOB:
	            __HAL_RCC_GPIOB_CLK_ENABLE();  // Enable the clock for GPIO Port B
	            break;
	        case (uint32_t)GPIOC:
	            __HAL_RCC_GPIOC_CLK_ENABLE();  // Enable the clock for GPIO Port C
	            break;
	        case (uint32_t)GPIOD:
	            __HAL_RCC_GPIOD_CLK_ENABLE();  // Enable the clock for GPIO Port D
	            break;
	        case (uint32_t)GPIOE:
	            __HAL_RCC_GPIOE_CLK_ENABLE();  // Enable the clock for GPIO Port E
	            break;
	        case (uint32_t)GPIOH:
	            __HAL_RCC_GPIOH_CLK_ENABLE();  // Enable the clock for GPIO Port H
	            break;
	        default:
	            // Invalid GPIO port, handle error if needed
	            return;
	    }
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
    // Step 2: Define a GPIO_InitTypeDef structure to hold the configuration
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Step 3: Configure Pin on Port as an output
    GPIO_InitStruct.Pin = GPIO_Pin;                 // Select Pin
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;       // Set as Push-Pull output
    GPIO_InitStruct.Pull = GPIO_NOPULL;               // No internal pull-up or pull-down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;      // Set output speed (LOW, MEDIUM, HIGH)

    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);           // Initialize the pin on Port
}


void LED_voidOn(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t copy_u8LedConnectionType)
{
	switch(copy_u8LedConnectionType)
	{
		case LED_FORWARD_CONNECTION:
			HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
			break;

		case LED_REVERSE_CONNECTION:
			HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
			break;

		default :
			// return Error State
			break;
	}
}


void LED_voidOff(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t copy_u8LedConnectionType)
{
	switch(copy_u8LedConnectionType)
		{
		case LED_FORWARD_CONNECTION:
			HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
			break;

		case LED_REVERSE_CONNECTION:
			HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
			break;

		default :
			// return Error State
			break;
		}
}


void LED_voidToggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
