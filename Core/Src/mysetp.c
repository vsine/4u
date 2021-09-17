#include "mysetp.h"
u8g2_t u8g2;
void setp(){
    HAL_Delay(100);
    u8g2Init(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_6x13_tr);
    while (1)
    {

        
        u8g2_DrawStr(&u8g2,0,10,"Volt:10V");
        u8g2_DrawLine(&u8g2,10,60,118,60);
        u8g2_DrawLine(&u8g2,10,20,10,60);
        u8g2_SendBuffer(&u8g2);
    }
    
}