/******************************************************************************
 *                                                                            *
 *************************  SWC     : SSD_private     *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_


                          /*************** MACROS FOR SSD NUMBERS ***************/

#define SSD_ZERO                (uint8_t)0x3f
#define SSD_ONE                 (uint8_t)0x06
#define SSD_TWO                 (uint8_t)0x5b
#define SSD_THREE               (uint8_t)0x4f
#define SSD_FOUR                (uint8_t)0x66
#define SSD_FIVE                (uint8_t)0x6d
#define SSD_SEX                 (uint8_t)0x7d
#define SSD_SEVEN               (uint8_t)0x07
#define SSD_EIGHT               (uint8_t)0x7f
#define SSD_NINE                (uint8_t)0x6f

/* Macros for SSD type */
#define SSD_COM_CATHODE			0
#define SSD_COM_ANNODE          1


#endif /* SSD_PRIVATE_H_ */
