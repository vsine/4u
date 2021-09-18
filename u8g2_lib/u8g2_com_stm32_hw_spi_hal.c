#include "u8g2_com_stm32_hw_spi_hal.h"
extern SPI_HandleTypeDef hspi1;
uint8_t u8x8_byte_4wire_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,void *arg_ptr)
{

    static uint8_t buffer[128];
    static uint8_t buf_idx;
    uint8_t *data;
    switch (msg)
    {
        case U8X8_MSG_BYTE_SEND:
            data = (uint8_t *)arg_ptr;
            while (arg_int > 0)
            {
                buffer[buf_idx++] = *data;
                data++;
                arg_int--;
            }
        break;
        case U8X8_MSG_BYTE_INIT:
        break;
        case U8X8_MSG_BYTE_SET_DC:
            HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
        break;
        case U8X8_MSG_BYTE_START_TRANSFER:
            buf_idx = 0;
        break;
        case U8X8_MSG_BYTE_END_TRANSFER:
            while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_READY);
            HAL_SPI_Transmit(&hspi1,buffer,buf_idx,1000);
            while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY){}
        break;
        default:
    return 0;
  }
  return 1;
}

uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,
    U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,
    U8X8_UNUSED void *arg_ptr)
{
  switch (msg)
  {
  case U8X8_MSG_GPIO_AND_DELAY_INIT:
     HAL_Delay(1);
        //LL_mDelay(1);
    break;
  case U8X8_MSG_DELAY_MILLI:
    //LL_mDelay(arg_int);
    HAL_Delay(1);
    break;
    case U8X8_MSG_GPIO_CS:
        HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, arg_int);
  case U8X8_MSG_GPIO_DC:
        
//    HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
        HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
    break;
  case U8X8_MSG_GPIO_RESET:
//    HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, arg_int);
        HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, arg_int);
    break;
  }
  return 1;
}


void u8g2Init(u8g2_t *u8g2)
{
    u8g2_Setup_ssd1306_128x64_noname_1(u8g2, U8G2_R0, u8x8_byte_4wire_hw_spi, u8x8_stm32_gpio_and_delay); // 初始化 u8g2 结构体
    u8g2_InitDisplay(u8g2);                                                                       // 根据所选的芯片进行初始化工作，初始化完成后，显示器处于关闭状态
    u8g2_SetPowerSave(u8g2, 0);                                                                   // 打开显示器
    u8g2_ClearBuffer(u8g2);
}
