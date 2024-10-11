/*
 *
 * @file KPD_config.h
 * @author Kareem Hussein
 * @brief configuration header file contain configuraron macros for KPD
 * @date 23/08/2024      
 * @version 1.0
 *
 */

#ifndef HAL_KPD_INC_KPD_CONFIG_H_
#define HAL_KPD_INC_KPD_CONFIG_H_

                        /* MACROS FOR KPD ROWS/COLS PORTS & PINS CONFIGURATION */
		 
// Input   
#define KPD_ROW0_PORT			GPIOA
#define KPD_ROW0_PIN 			GPIO_PIN_11

#define KPD_ROW1_PORT			GPIOA
#define KPD_ROW1_PIN 			GPIO_PIN_10

#define KPD_ROW2_PORT			GPIOA
#define KPD_ROW2_PIN 			GPIO_PIN_9

#define KPD_ROW3_PORT			GPIOA
#define KPD_ROW3_PIN 			GPIO_PIN_8


//Output
#define KPD_COL0_PORT			GPIOB
#define KPD_COL0_PIN 			GPIO_PIN_15
			
#define KPD_COL1_PORT			GPIOA
#define KPD_COL1_PIN 			GPIO_PIN_14
			
#define KPD_COL2_PORT			GPIOA
#define KPD_COL2_PIN 			GPIO_PIN_13
			
#define KPD_COL3_PORT			GPIOA
#define KPD_COL3_PIN 			GPIO_PIN_12


#define KPD_KEYS			    {{'1','2','3','A'},\
                                 {'4','5','6','B'},\
								 {'7','8','9','C'},\
								 {'*','0','#','D'}}


#endif /* HAL_KPD_INC_KPD_CONFIG_H_ */
