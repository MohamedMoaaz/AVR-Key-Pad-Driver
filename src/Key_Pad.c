/**
 * @file    Key_PAD.c
 * @author  Mohamed Moaaz
 * @brief   Key_PAD program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/DIO_interface.h"
#include "HAL/KPD_configuration.h"
#include "HAL/KPD_private.h"
#include "HAL/KPD_interface.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

//==============================================================================
// Global Variables
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================

uint8_t KPD_u8GetPressedKey(void)
{
    uint8_t Local_u8PressedKey = KPD_NO_PRESSED_KEY, Local_u8ColIndex, Local_u8RowIndex, Local_u8PinState;
    static uint8_t Local_u8KPDArr[COLUMN_NUM][ROW_NUM] = KPD_ARR_VAL;
    static uint8_t KPD_COLUMN_ARR[COLUMN_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
    static uint8_t KPD_ROW_ARR[ROW_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

    for (Local_u8ColIndex = 0; Local_u8ColIndex < COLUMN_NUM; Local_u8ColIndex++)
    {
        DIO_u8SetPinValue(KPD_PORT, KPD_COLUMN_ARR[Local_u8ColIndex], DIO_u8PIN_LOW);

        for (Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUM; Local_u8RowIndex++)
        {
            DIO_u8GetPinValue(KPD_PORT, KPD_ROW_ARR[Local_u8RowIndex], &Local_u8PinState);

            if (DIO_u8PIN_LOW == Local_u8PinState)
            {
                Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColIndex];
                /*polling (busy waiting) till the key is released*/
                while(DIO_u8PIN_LOW == Local_u8PinState)
                {
                    DIO_u8GetPinValue(KPD_PORT, KPD_ROW_ARR[Local_u8RowIndex], &Local_u8PinState);
                }
                return Local_u8PressedKey;
            }
        }
        DIO_u8SetPinValue(KPD_PORT, KPD_COLUMN_ARR[Local_u8ColIndex], DIO_u8PIN_HIGH);
    }
    return Local_u8PressedKey;
}