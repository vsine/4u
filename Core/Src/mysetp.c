#include "mysetp.h"

u8g_t u8g;
void setp(){
    u8g_InitComFn(&u8g,&u8g_dev_ssd1306_128x64_i2c,u8g_com_hw_i2c_fn);
    HAL_Delay(11);
    u8g_DrawLine(&u8g,10,10,40,40);
    while (1)
    {
       u8g_FirstPage(&u8g);
       do
       {
          u8g_DrawLine(&u8g,10,10,40,40);
       } while (u8g_NextPage(&u8g));
       
    }
    
}