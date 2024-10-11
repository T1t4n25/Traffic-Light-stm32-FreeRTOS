/******************************************************************************
 *                                                                            *
 *************************  SWC     : SSD_interface   *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* Macros for SSD id */
#define SSD_A			1
#define SSD_B		    2


                   /*************** APIS PROTO TYPES ***************/

void SSD_voidInit                    (void);
void SSD_voidDisplayNumber           (uint8_t copy_u8DesiredNumber, uint8_t copy_u8Id);
void SSD_voidDisplayMultiplexedNumber(uint8_t copy_u8DesiredNumber);

#endif /* SSD_INTERFACE_H_ */
