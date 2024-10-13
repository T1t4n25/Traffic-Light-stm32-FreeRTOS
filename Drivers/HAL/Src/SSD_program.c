/******************************************************************************
 *                                                                            *
 *************************  SWC     : SSD_program     *************************
 *************************  Date    : 28/09/2024      *************************
 *************************  Author  : Zeyad Hemeda  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

/* MCAL */
#include "main.h"

/* HAL */
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

static uint8_t PRV_u8Numbers[10]= {SSD_ZERO, SSD_ONE, SSD_TWO, SSD_THREE, SSD_FOUR, SSD_FIVE, SSD_SEX, SSD_SEVEN, SSD_EIGHT, SSD_NINE};

void SSD_voidInit(void)
{

	switch ((uint32_t)SSD_ENABLE_PORT) {
			case (uint32_t)GPIOA:
				__HAL_RCC_GPIOA_CLK_ENABLE();
				break;
			case (uint32_t)GPIOB:
				__HAL_RCC_GPIOB_CLK_ENABLE();
				break;
			case (uint32_t)GPIOC:
				__HAL_RCC_GPIOC_CLK_ENABLE();
				break;
			case (uint32_t)GPIOD:
				__HAL_RCC_GPIOD_CLK_ENABLE();
				break;
			case (uint32_t)GPIOE:
				__HAL_RCC_GPIOE_CLK_ENABLE();
				break;
			case (uint32_t)GPIOH:
				__HAL_RCC_GPIOH_CLK_ENABLE();
				break;
			default:
				// Invalid GPIO port, handle error if needed
			return;
	}

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = SSD_K1_ENABLE_PIN | SSD_K2_ENABLE_PIN;                 // Select Pin
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;       // Set as Push-Pull output
    GPIO_InitStruct.Pull = GPIO_NOPULL;               // No internal pull-up or pull-down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;      // Set output speed (LOW, MEDIUM, HIGH)

    HAL_GPIO_Init(SSD_ENABLE_PORT, &GPIO_InitStruct);           // Initialize the pin on Port

	HAL_GPIO_WritePin(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, GPIO_PIN_RESET);

	switch ((uint32_t)SSD_DATA_PORT) {
		case (uint32_t)GPIOA:
				__HAL_RCC_GPIOA_CLK_ENABLE(); 
			break;
		case (uint32_t)GPIOB:
				__HAL_RCC_GPIOB_CLK_ENABLE(); 
			break;
		case (uint32_t)GPIOC:
				__HAL_RCC_GPIOC_CLK_ENABLE(); 
			break;
		case (uint32_t)GPIOD:
				__HAL_RCC_GPIOD_CLK_ENABLE(); 
			break;
		case (uint32_t)GPIOE:
				__HAL_RCC_GPIOE_CLK_ENABLE(); 
			break;
		case (uint32_t)GPIOH:
				__HAL_RCC_GPIOH_CLK_ENABLE(); 
			break;
		default:
			// Invalid GPIO port, handle error if needed
		return;
	}


    GPIO_InitStruct.Pin = SSD_DATA_PIN_0|SSD_DATA_PIN_1|SSD_DATA_PIN_2|SSD_DATA_PIN_3|SSD_DATA_PIN_4|SSD_DATA_PIN_5|SSD_DATA_PIN_6; // Select Pin
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;       // Set as Push-Pull output
    GPIO_InitStruct.Pull = GPIO_NOPULL;               // No internal pull-up or pull-down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;      // Set output speed (LOW, MEDIUM, HIGH)

    HAL_GPIO_Init(SSD_DATA_PORT, &GPIO_InitStruct);           // Initialize the pin on Port


	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_2, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_6, GPIO_PIN_RESET);

}


void SSD_voidDisplayNumber(uint8_t copy_u8DesiredNumber, uint8_t copy_u8Id)
{

	if(copy_u8DesiredNumber<=9)
	{
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_0, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_6, GPIO_PIN_RESET);
		switch(copy_u8Id)
		{
		    case SSD_A:
				#if SSD_TYPE == SSD_COM_ANNODE

				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_0, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 0
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_1, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 1
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_2, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 2
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_3, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 3
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_4, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 4
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_5, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 5
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_6, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 6

				HAL_GPIO_WritePin(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, GPIO_PIN_RESET);

				#elif SSD_TYPE == SSD_COM_CATHODE
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_0, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 0
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_1, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 1
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_2, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 2
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_3, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 3
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_4, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 4
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_5, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 5
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_6, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 6

				HAL_GPIO_WritePin(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, GPIO_PIN_SET);
				#endif
					break;

			case SSD_B:
				#if SSD_TYPE == SSD_COM_ANNODE
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_0, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 0
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_1, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 1
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_2, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 2
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_3, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 3
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_4, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 4
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_5, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 5
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_6, ((PRV_u8Numbers[copy_u8DesiredNumber]) & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 6

				HAL_GPIO_WritePin(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, GPIO_PIN_RESET);

				#elif SSD_TYPE == SSD_COM_CATHODE
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_0, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 0
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_1, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 1
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_2, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 2
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_3, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 3
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_4, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 4
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_5, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 5
				HAL_GPIO_WritePin(SSD_DATA_PORT, SSD_DATA_PIN_6, (~(PRV_u8Numbers[copy_u8DesiredNumber]) & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);  // Bit 6

				HAL_GPIO_WritePin(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, GPIO_PIN_SET);
				#endif
			break;
		}
	}
	else
	{
		// return Error state
	}
}


void SSD_voidDisplayMultiplexedNumber(uint8_t copy_u8DesiredNumber)
{
	if(copy_u8DesiredNumber<=99)
	{
		uint8_t local_u8Ones = copy_u8DesiredNumber%10;
		uint8_t local_u8Tens = copy_u8DesiredNumber/10;

		HAL_GPIO_TogglePin(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN);
		SSD_voidDisplayNumber(local_u8Tens, SSD_A);
		HAL_Delay(5);
		HAL_GPIO_TogglePin(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN);
		SSD_voidDisplayNumber(local_u8Ones, SSD_B);
		HAL_Delay(5);
	}
	else
	{
		// return Error state
	}
}
