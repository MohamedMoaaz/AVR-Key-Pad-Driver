/**
 * @file    KPD_configuration.h
 * @author  Mohamed Moaaz
 * @brief   KPD configuration file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __KPD_CONFIGURATION_H__
#define __KPD_CONFIGURATION_H__

//==============================================================================
// Macros & Defines
//==============================================================================

#define KPD_PORT                DIO_u8PORTB
#define KPD_NO_PRESSED_KEY      0xff

#define KPD_COLUMN0_PIN         DIO_u8PIN0
#define KPD_COLUMN1_PIN         DIO_u8PIN1
#define KPD_COLUMN2_PIN         DIO_u8PIN2
#define KPD_COLUMN3_PIN         DIO_u8PIN3

#define KPD_ROW0_PIN            DIO_u8PIN4
#define KPD_ROW1_PIN            DIO_u8PIN5
#define KPD_ROW2_PIN            DIO_u8PIN6
#define KPD_ROW3_PIN            DIO_u8PIN7

#define KPD_ARR_VAL             {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __KPD_CONFIGURATION_H__ */