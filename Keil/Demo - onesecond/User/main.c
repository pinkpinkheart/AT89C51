#include <reg51.h>
sbit led=P0^0;
int i=0;
int main()
{
        TMOD= 0x10;
        TH1 = 0x0b;
        TL1 = 0xdc;
        IE  = 0x88;
        TR1=1;
        led=0;
        while(1);
}
void T1_hander () interrupt 3
{
        TR1 = 0;
        TH1 = 0x0b;
        TL1 = 0xdc;
        TR1 = 1 ;
        i++;
        if(i>=16)
        {
                i=0;
                led=~led;
        }
}