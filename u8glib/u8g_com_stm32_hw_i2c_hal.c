#include "u8g.h"



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
  switch(msg)
  {
    case U8G_COM_MSG_INIT:
      break;
    case U8G_COM_MSG_STOP:
      break;

   
    case U8G_COM_MSG_CHIP_SELECT:
      /* arg_val contains the chip number, which should be enabled */
      break;


    case U8G_COM_MSG_WRITE_BYTE:
      break;
    case U8G_COM_MSG_WRITE_SEQ:
      break;
  }
  return 1;
}