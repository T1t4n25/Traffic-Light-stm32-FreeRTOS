/******************************************************************************
 *                                                                            *
 *************************  SWC     : SSD_config      *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_


                           /* Macros for SSD decoder Pins Configurations */
						   
#define SSD_ENABLE_PORT			        GPIOB
#define SSD_K1_ENABLE_PIN			    GPIO_PIN_1
#define SSD_K2_ENABLE_PIN			    GPIO_PIN_0



#define SSD_DATA_PORT					GPIOB
#define SSD_DATA_PIN_0					GPIO_PIN_9
#define SSD_DATA_PIN_1					GPIO_PIN_8
#define SSD_DATA_PIN_2					GPIO_PIN_7
#define SSD_DATA_PIN_3					GPIO_PIN_6
#define SSD_DATA_PIN_4					GPIO_PIN_5
#define SSD_DATA_PIN_5					GPIO_PIN_4
#define SSD_DATA_PIN_6					GPIO_PIN_3

/* Options FOR SSD Type:
1- SSD_COM_CATHODE
2- SSD_COM_ANNODE
*/

#define SSD_TYPE                        SSD_COM_CATHODE
#endif /* SSD_CONFIG_H_ */
