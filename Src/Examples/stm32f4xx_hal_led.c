/**
  ******************************************************************************
  * @file    stm32f4xx_hal_led.c
  * @author  MrAbhi19
  * @brief   Beginner-friendly example: Blink LED using HAL + register notes
  ******************************************************************************
  */

#include "stm32f4xx_hal.h"

/* 
   NOTE: This example assumes LED is connected to GPIO Port D, Pin 12 
   (common on STM32F4 Discovery board). Adjust pin/port as needed.
*/

int main(void)
{
    // 1. Initialize HAL Library
    HAL_Init();

    // 2. Enable GPIO Port D clock
    __HAL_RCC_GPIOD_CLK_ENABLE();

    // 3. Configure GPIO pin for LED
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_12;        // Select Pin 12
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Output, Push-Pull
    GPIO_InitStruct.Pull = GPIO_NOPULL;       // No pull-up/pull-down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Low speed
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* 
       REGISTER EXPLANATION:
       - RCC_AHB1ENR: Bit 3 enables clock for GPIOD
       - GPIOD_MODER: Bits [25:24] set mode for Pin 12 (01 = Output)
       - GPIOD_OTYPER: Bit 12 sets output type (0 = Push-Pull)
       - GPIOD_OSPEEDR: Bits [25:24] set speed
       - GPIOD_PUPDR: Bits [25:24] configure pull-up/pull-down
       - GPIOD_ODR: Bit 12 controls LED ON/OFF
    */

    // 4. Blink loop
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); // Toggle LED
        HAL_Delay(500); // 500 ms delay
    }
}
