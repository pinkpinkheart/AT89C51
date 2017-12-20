#include <reg51.h>
sbit led=P0^0;
sbit key=P2^0;
sbit int0=P3^2;
void delay(int t)
{
        for(;t>0;t--);
}
int main()
{
        IT0 = 1;
        IE = 0x81;
        key=1;
        led=1;
        while(1)
        {
                
        }
}
void INT0_handler () interrupt 0
{
        if (key==0)
        {
                delay(50);
                if(key==0)
                {
                        led=~led;
                }
                
        }
}