#include <reg51.h>
int flickerflag=0;
int i;
unsigned char ledvalue;
unsigned char keyvalue;
unsigned char ledvalue=0xfe;
void delay(int t)
{
        for(;t>0;t--);
}
int keyscan(void)
{
        keyvalue=0xff;
        if(P2!=0xff)
        {
                delay(10);
                if(P2!=0xff)
                {
                        keyvalue=P2;
                        while((i<100)&&(P2!=0xff))
                        {
                                i++;
                                delay(50);
                        }
                }
        }
        return keyvalue;
}
void keycontrol (unsigned char keyvalue)
{
        switch(keyvalue)
        {
                case(0xfb):if(ledvalue!=0x7f)ledvalue=~((~ledvalue)<<1);break;
                case(0xfd):flickerflag=~flickerflag;break;
                case(0xfe):if(ledvalue!=0xfe)ledvalue=~((~ledvalue)>>1);break;
        }
}
int main()
{
        IT0 = 1;
        IE=0x81;
        
        while(1)
        {
                
                
                P0=ledvalue;
                delay(50);
                
                if(flickerflag!=0)
                {
                        P0=0xff;
                        delay(50);
                }
                
        }

}
void INT0_handler() interrupt 0
{
        keycontrol(keyscan());
}