/*
 * LED_interface.h
 *
 *  Created on: 26/09/2024
 *      Author: Zeyad Hemeda
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


#define LED_FORWARD_CONNECTION			1
#define LED_REVERSE_CONNECTION			2

                 /*************** APIS PROTO TYPES ***************/

void LED_voidInit  (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void LED_voidOn    (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t copy_u8LedConnectionType);
void LED_voidOff   (GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t copy_u8LedConnectionType);
void LED_voidToggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif /* LED_INTERFACE_H_ */
