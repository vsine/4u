#include "u8g.h"
#include "main.h"
extern I2C_HandleTypeDef hi2c1;


void u8g_Delay(uint16_t val)
 {
   HAL_Delay(val);
 }
 
 void u8g_MicroDelay()
{

 }
void u8g_10MicroDelay()
{

}



uint8_t u8g_com_hw_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr)
{
    static uint8_t buffer[128];
    static uint8_t buf_idx;
    uint8_t *data;
  switch(msg)
  {
    case U8G_COM_MSG_INIT:
      break;
    case U8G_COM_MSG_STOP:
      break;


    case U8G_COM_MSG_CHIP_SELECT:
      /* arg_val contains the chip number, which should be enabled */
      if (arg_val==0)
         buf_idx=0;
      
      
      break;


    case U8G_COM_MSG_WRITE_BYTE:
        if (HAL_I2C_Master_Transmit(&hi2c1, (0x78), buffer, buf_idx,1000) != HAL_OK)
               return 0;
      break;
    case U8G_COM_MSG_WRITE_SEQ:
        data = (uint8_t *)arg_ptr;
        while (arg_val > 0)
        {
            buffer[buf_idx++] = *data;
            data++;
            arg_val--;
        }
      break;
  }
  return 1;
}