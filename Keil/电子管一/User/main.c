#include <reg51.h>
unsigned char SegCode[10]={ 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,0x3F};
unsigned char w[]={3,4,5,9,4,7};
int main()
{
        int i;
        int t;
       int a;
        while(1)
        {
                int m=0x01;
                a=0;
                for((t=0);t<6;t++)
                {
                        P1=~m;
                        m=m<<1;
                        if(t==1||t==3)
                        {
                                P0 = SegCode[t]|0x80;
                        }
                        else
                        P0 = SegCode[t];
                        a++;
                        for(i = 100; i > 0; i--);
                }
        }
}