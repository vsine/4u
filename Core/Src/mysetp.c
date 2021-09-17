#include "mysetp.h"
u8g2_t u8g2;
void setp(){
 
    u8g2Init(&u8g2);
    u8g2_SetFont(&u8g2, u8g2_font_6x13_tr);
    while (1)
    {
        u8g2_DrawStr(&u8g2,0,10,"Neotoxic");
    }
    
}