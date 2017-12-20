#include <reg51.h>
#define u8 unsigned char
sbit k1=P2^1;
sbit k2=P2^2;
sbit k3=P2^3;
sbit k4=P2^4;
sbit m1=P2^0;
sbit m2=P2^7;
u8 SegCode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
u8 wei[2]={0xfe , 0xfd};
int l[2]={5,0};
u8 i;
u8 m;
u8 j;
u8 a;
u8 b;
void delay (u8 t)
{
        for(t; t> 0; t--)
        {
                for(j = 1000; j > 0; j--);
        }
}
void keycontral (void)
{
        if(0==k1)
        {
                
                m1=~m1;
                a=m1;
                b=m2;
        }
        else if(0==k2)
        {
                m1=~m1;
                m2=~m2;
                a=m1;
                b=m2;//反向转动
        }
        else if(0==k3)//+3
        {
                if(l[1]<7)
                {
                        l[1]=l[1]+3;
                }
                else if(l[1]>6)
                {
                        if(l[0]!=9)
                        {
                                l[0]=l[0]+1;
                                l[1]=l[1]-7;
                        }
                        else
                        {
                                l[0]=l[1]=9;
                        }
                }//显示器的变化
        }
        else if(0==k4)//-5
        {
                if(l[1]>4)
                {
                        l[1]=l[1]-5;
                }
                else if(l[1]<5)
                {
                        if(l[0]!=0)
                        {
                                l[0]=l[0]-1;
                                l[1]=l[1]+5;
                        }
                        else
                        {
                                l[0]=l[1]=0;
                        }
                }//显示器的变化
        }
        m=10*l[0]+l[1];
}
void zhuandong(void)
{
        delay(1);
        P2=0xff;
        delay((100/m)-1);
        m1=a;
        m2=b;
}
int main()
{
        IT0=1;
        IE=0x81;
        P2=0xff;
        while(1)
        {
                for(i=0;i<2;i++)
                {
                        P1=wei[i];
                        P0=SegCode[l[i]];
                        delay(1);
                }
                zhuandong();
        }
}
void INT0_HANDER() interrupt 0
{
        keycontral();
}