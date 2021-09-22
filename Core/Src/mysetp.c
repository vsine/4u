#include "mysetp.h"
#include "stdlib.h"

u8g2_t u8g2;
int now=1;
int aim=20;
extern TIM_HandleTypeDef htim2;

void setp(){
    HAL_Delay(1000);
    u8g2Init(&u8g2);
    HAL_Delay(1000);
    while (1)
    {
        u8g2_ClearBuffer(&u8g2);
        showInfo();
        showTemp(now);
        //if (now<aim)
        //now+=(now/70)+1;
        //osDelay(1);
        if (now>300)
        {
           now=1;
        }
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,aim*10);

         //HAL_Delay(1000);
        //u8g2_SetFont(&u8g2, u8g2_font_open_iconic_all_4x_t);
        //u8g2_DrawGlyph(&u8g2, 90,60,0x008D);
        u8g2_SendBuffer(&u8g2);
    }
    
}
void showInfo(){
        u8g2_SetFont(&u8g2, u8g2_font_6x13_tr);
        if (now%3==0)
        u8g2_DrawStr(&u8g2,0,13,"Heating.");
        else if (now%3==1)
        u8g2_DrawStr(&u8g2,0,13,"Heating..");
        else if (now%3==2)
        u8g2_DrawStr(&u8g2,0,13,"Heating...");
        u8g2_DrawStr(&u8g2,80,13,"Aim:");
        char kk[20]={0};
        itoa(aim,kk,10);
        u8g2_DrawStr(&u8g2,104,13,kk);

        u8g2_DrawStr(&u8g2,80,33,"P:");
        u8g2_DrawStr(&u8g2,94,33,"0.1");
        u8g2_DrawStr(&u8g2,80,46,"I:");
        u8g2_DrawStr(&u8g2,94,46,"2.3");
        u8g2_DrawStr(&u8g2,80,59,"D:");
        u8g2_DrawStr(&u8g2,94,59,"0.8");
        ///
}
void showTemp(int temp){

        u8g2_SetFont(&u8g2, u8g2_font_10x20_tr);
        char kk[20]={0};
        itoa(temp,kk,10);
        u8g2_DrawStr(&u8g2,20,50,kk);
        if(temp<10){
        u8g2_DrawStr(&u8g2,35,50,"C");
        u8g2_DrawCircle(&u8g2,34,35,2,U8G2_DRAW_ALL);
        }
        else if(temp<100){
        u8g2_DrawStr(&u8g2,45,50,"C");
        u8g2_DrawCircle(&u8g2,44,35,2,U8G2_DRAW_ALL);
        }
        else{
        u8g2_DrawStr(&u8g2,55,50,"C");
        u8g2_DrawCircle(&u8g2,54,35,2,U8G2_DRAW_ALL);
        }
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

    if (GPIO_Pin==GPIO_PIN_15)
    {
        aim++;
    }
    if (GPIO_Pin==GPIO_PIN_13)
    {
        if (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14))
        {
             aim++;
        }else{

            aim--;
        }
        
    }
}

