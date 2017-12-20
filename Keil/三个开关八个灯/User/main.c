#include <reg51.h>
void delay(unsigned int t)//延时
{
  for(;t>0;t--);
}
unsigned char flickerflag=0;

unsigned char ledvalue=0xfe;
unsigned char keyvalue;
int keyscan(void)//捕获p2的值
{unsigned char i=0;
   keyvalue=0xff;
   if(P2!=0xff)
        {
                delay(50);
                if(P2!=0xff)
                {
                        keyvalue=P2;
                        while((i<=100)&&(P2!=0xff))
                        {
                                i++;//i=(i=(i+1)))
                                delay(50);
                        }
                }
        }
        return keyvalue;
}
void keycontrol(unsigned char keyvalue)
{
        switch (keyvalue)
        {
                case (0xfe):if(ledvalue!=0xfe) ledvalue=~((~ledvalue)>> 1);break;
                case (0xfd):flickerflag=~flickerflag;break;
                case (0xfb):if(ledvalue!=0x7f) ledvalue=~((~ledvalue)<< 1);break;
        }
}
int main()
{
        while(1)
        {
                keycontrol(keyscan());
                P0=ledvalue;
                delay(50);
                if(flickerflag!=0)
                {
                        P0=0xff;
                        delay(50);
                        
                }
        }
}
