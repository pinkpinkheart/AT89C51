#include <reg51.h>
#define u8 unsigned char
u8 SegCode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
wei[4]={0xfe,0xfd,0xfb,0xf7};
luan[4]={5,8,3,0};
u8 i;
void delay(u8 t)
{
        u8 j;
        for(;t>0;t--)
        {
                for(j=1000;j>0;j--);
        }
}
int main()
{
        while(1)
        {
                for(i=0;i<4;i++)
                {
                        P2=wei[i];
                        P1=SegCode[luan[i]];
                        delay(1);
                }
        }
}