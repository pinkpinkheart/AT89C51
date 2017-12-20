#include <reg51.h>
#define u8 unsigned char
u8 n;

sbit sele = P1^0;
sbit button = P1^4;
sbit led = P1^3;

void delay(int i)
{
        int j;
        for(j=100;j>0;j--)
        for(;i>0;i--);
}

void init (void)  //config
{

        TMOD=0x20;      //定时器方式二
        TH1=0xfd;
        TL1=0xfd;       //八位自动重装载
        TR1=1;
        EA=1;           //开启总中断
        ES=1;           //串口中断
        REN=1;          //接收允许
        RI=0;           //接收中断
        TI=0;           //发出中断
        SM0=0;
        SM1=1;          //控制方式1   10位异步
}
int main()
{
        init();
        while(1)
        {
                if(sele==0)                     //发射机
                {
                        if(button==0)
                        {
                                delay(1);
                                if(button==0)
                                {
                                        while(button==0);
                                        SBUF=0xff;
                                        n=0xff;
                                }
                        }
                                
                }
        }
}

void hander() interrupt 4
{
        u8 recevierdate;
        recevierdate=SBUF;
        if(RI)
        {
                TI=0;
                if(sele==1)
                {
                        if(recevierdate==0xff)
                        {
                                led=~led;
                        }
                        RI=0;
                }
        }
}