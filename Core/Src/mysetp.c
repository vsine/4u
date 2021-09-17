#include "mysetp.h"

u8g_t u8g;
void setp(){
    u8g_InitComFn(&u8g,&u8g_dev_ssd1306_128x64_2x_i2c,u8g_com_hw_i2c_fn);

}