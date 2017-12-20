//定时器控制灯泡闪烁1hz，外部中断控制亮灭
#include <reg51.h>
#define u8 unsigned char
sbit led =P2^0 ;
sbit key =P3^2 ;
void delay (u8 t);
u8 InterruptCount=0;
int main()
{
        led = 1;
        IE=0X9F;     //打开总中断
        IT0 = 1;    //跳变沿触发中断
        TCON = 0x02;    //8位自动重装载
        TH0 = 0x0b;
        TL0 = 0xdc;     //中断时间1s
        TR0 = 1;
        while(1)
        {
                
        }
}
void INT0_Handler() interrupt 0
{
        TR0 = 0;
        led = 0;
}


void TIM0_Handler() interrupt 1
{
        InterruptCount++;
        if(InterruptCount >= 16)
        {
                InterruptCount = 0;
                led = ~led;
        }
}













//#include <reg51.h>
//#define u8 unsigned char
//sbit led =P2^0 ;
//sbit key =P3^2 ;
//void delay (u8 t);
//void Key_Control();
//u8 Key_Scan();
//int main()
//{
//        
//}
//void delay (u8 t)           //延时函数
//{
//        u8 i;
//        for(i=1000;i>0;i--)
//        {
//                for(;t>0;t--);
//        }
//}
//u8 Key_Scan()                             //1亮，0灭
//{
//        u8 KeyValue = 0;
//        u8 i;
//        i=0;
//        if(0 == key)
//        {
//                delay(1);
//                if(0 == key)
//                {
//                        KeyValue = ~ KeyValue;
//                        while((i < 20) && (P2 != 0xff))
//                        {
//                        delay(1);
//                        i++;
//                        }
//                }
//        }
//        return KeyValue;
//}
//void Key_Control(u8 t)
//{
//        if(0==t)
//        {
//                led=0;
//        }
//        else led=1;
//}
//void INT0_Handler() interrupt 0
//{
//        Key_Control(Key_Scan());
//}