#include "u8g.h"
#include "main.h"
extern I2C_HandleTypeDef hi2c1;
 static uint8_t control = 0;  

void u8g_Delay(uint16_t val)
 {
   HAL_Delay(val);
 }
 
 void u8g_MicroDelay()
{
int i;  
  for (i = 0; i < 1000; i++);  

 }
void u8g_10MicroDelay()
{
     int i;  
      for (i = 0; i < 10000; i++);  
}



uint8_t u8g_com_hw_i2c_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr)
{

  switch(msg)
  {
    case U8G_COM_MSG_INIT:
        u8g_MicroDelay();  
      break;
    case U8G_COM_MSG_STOP:

      break;
    case U8G_COM_MSG_ADDRESS:
        u8g_10MicroDelay();  
        if (arg_val == 0)  
         control = 0;  
    else  
         control = 0x40;  
    break;

    case U8G_COM_MSG_CHIP_SELECT:
      /* arg_val contains the chip number, which should be enabled */
     
      
      
      break;


    case U8G_COM_MSG_WRITE_BYTE:{
        uint8_t buffer[2];  
        buffer[0] = control;  
        buffer[1] = arg_val;  
        HAL_I2C_Master_Transmit(&hi2c1, 0x78, (uint8_t*) buffer, 2, 1000);  
    }
      break;
    case U8G_COM_MSG_WRITE_SEQ:
    case U8G_COM_MSG_WRITE_SEQ_P:
    {
        uint8_t buffer[1000];  
           uint8_t *ptr = arg_ptr;  
           buffer[0] = control;  
           for (int i = 1; i <= arg_val; i++)  
           {  
                buffer[i] = *(ptr++);  
           }  
           HAL_I2C_Master_Transmit(&hi2c1, 0x78, (uint8_t *)buffer, arg_val, 1000);  
   
   }
      break;
  }
  return 1;
}