#include <reg51.h>
#define u8 unsigned char

u8 n;

void init (void)
{
        P1=0xfd;
                TMOD = 0x20;      //定时器方式二
                TH1  = 0xfd;
                TL1  = 0xfd;       //八位自动重装载
                TR1  = 1;
                EA   = 1;           //开启总中断
                ES   = 1;           //串口中断
                REN  = 1;          //接收允许
                RI   = 0;           //接收中断
                TI   = 0;           //发出中断
                SM0  = 0;
                SM1  = 1;          //控制方式1   10位异步
}
//void delay(int i)
//{
//        int j;
//        for(j=100;j>0;j--)
//        for(;i>0;i--);
//}
int main()
{
        init();
        while(1)
        {
//                SBUF=n;
//                while(!TI);
//                TI=0;
//                n++;
//                delay(50);
        }
}
void hander () interrupt 4
{
        while (RI)
        {
                P1 = SBUF;
                RI = 0;
                TI = 0;
        }
}