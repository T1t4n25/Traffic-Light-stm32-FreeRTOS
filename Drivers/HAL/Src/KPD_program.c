/*
 *
 * @file KPD_program.c
 * @author Zeyad Hemeda
 * @brief main source for KPD functions implementation
 * @date 26/09/2024
 * @version 1.0
 *
 */


/* UTILES_LIB */

/* MCAL */
#include "main.h"

/* HAL */
#include "KPD_config.h"
#include "KPD_interface.h"


/*
 * @fn KPD_voidInit
 * @brief the function initializes the KPD ROWS pins as I/P with PullUp and COLS pins as O/P initialy high
 * @param[in] void
 * @retVal void
 */
void KPD_voidInit(void)
{
	HAL_GPIO_WritePin(KPD_ROW0_PORT, KPD_ROW0_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KPD_ROW1_PORT, KPD_ROW1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KPD_ROW2_PORT, KPD_ROW2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KPD_ROW3_PORT, KPD_ROW3_PIN, GPIO_PIN_SET);

	/* Activate Internal pull up for ROWS pins */
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	// Configure ROW0 pin as input with pull-up resistor
	GPIO_InitStruct.Pin = KPD_ROW0_PIN|KPD_ROW1_PIN|KPD_ROW2_PIN|KPD_ROW3_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(KPD_ROW0_PORT, &GPIO_InitStruct);

	/* Config COLS pins as O/P pins */
	HAL_GPIO_WritePin(KPD_COL0_PORT, KPD_COL0_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(KPD_COL1_PORT, KPD_COL1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(KPD_COL2_PORT, KPD_COL2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(KPD_COL3_PORT, KPD_COL3_PIN, GPIO_PIN_RESET);

	/* Set COLS pins as Initialy high */ 
	HAL_GPIO_WritePin(KPD_COL0_PORT, KPD_COL0_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KPD_COL1_PORT, KPD_COL1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KPD_COL2_PORT, KPD_COL2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KPD_COL3_PORT, KPD_COL3_PIN, GPIO_PIN_SET);
}


/*
 * @fn KPD_voidGetValue
 * @brief the function Loop on COLS and activate each one, Loop on ROWS and check each one  
 * @param[out] copy_pu8ReturnedValue: The ASCII of pressed key if there is one.
 * @retVal void
 */
void KPD_voidGetValue(uint8_t* copy_pu8ReturnedValue)
{
	if(copy_pu8ReturnedValue != NULL)
	{
		uint8_t local_u8ColsCounter, local_u8RowsCounter;
		GPIO_PinState local_PinState;
		uint8_t local_u8ColsPorts[4] = {KPD_COL0_PORT, KPD_COL1_PORT, KPD_COL2_PORT, KPD_COL3_PORT};
		uint8_t local_u8ColsPins [4] = {KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN};
		uint8_t local_u8RowsPorts[4] = {KPD_ROW0_PORT, KPD_ROW1_PORT, KPD_ROW2_PORT, KPD_ROW3_PORT};
		uint8_t local_u8RowsPins [4] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
		uint8_t local_u8KPD_Chars[4][4] = KPD_KEYS;

		*copy_pu8ReturnedValue = KPD_NOT_PRESSED;
		for(local_u8ColsCounter = 0;local_u8ColsCounter < 4; local_u8ColsCounter++)
		{
			/* Activate Each Column with low value */
			HAL_GPIO_WritePin(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], GPIO_PIN_RESET);
			for(local_u8RowsCounter = 0; local_u8RowsCounter < 4; local_u8RowsCounter++)
			{
				/* Check Each Row (if == 0?) */
				local_PinState = HAL_GPIO_ReadPin(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter]);
				/* Is Pressed? */
				if(GPIO_PIN_RESET == local_PinState)
				{
					while(GPIO_PIN_RESET == local_PinState)
					{
						local_PinState = HAL_GPIO_ReadPin(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter]);
					}
					*copy_pu8ReturnedValue = local_u8KPD_Chars[local_u8RowsCounter][local_u8ColsCounter];
					break;
				}
			}

			/* Deactivate Current Column with high value */
			HAL_GPIO_WritePin(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], GPIO_PIN_SET);

			if(local_u8RowsCounter < 4)
			{
				break;
			}
		}
	}
	else
	{
		// return Error State
	}
}

