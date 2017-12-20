#include <reg51.h>
#define u8 unsigned char
int a;//初始页面控制
int i;//松手检测
int m;//闪烁循环
int z;//控制闪烁
int v;//调整时间
int y=0;//一秒钟
int keyvalue;
int flickerflag=0;
u8 SegCode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};//位选
u8 duan[6]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};//段选
u8 luan[6]={2,3,5,9,5,0};
void delay(unsigned int t)
{
        for(;t>0;t--);
}
u8 keyscan(void)//捕获P2
{
        keyvalue=0xff;
        if(P2!=0xff)
        {
                delay(50);
                if(P2!=0xff)
                {
                        keyvalue=P2;
                        while ((i<20)&&(P2!=0xff))
                        {
                                i++;
                                delay(500);
                        }
                }
        }
        return keyvalue;
}
void keycontrol (u8 keyvalue)
{
        switch(keyvalue)
        {
                case(0xf7)://闪烁
                {
                        flickerflag=~flickerflag;
                        z=1;
                }
                break;
                case(0xfb):
                {
                        z=z+1;
                        if(z==7)z=1;
                }
                break;       //               z-1  是当前的值；
                case(0xfd):
                {
                        v=0x01;
                        a=z;
                        for(;a>1;a--)
                        {
                                v=v<<1;
                        }
                        switch(v)
                        {
                                case(0x01):
                                {
                                        if((luan[0]==0)||((luan[0]==1)&&(luan[1]<4)))
                                        {
                                                luan[0]=luan[0]+1;
                                        }
                                        else if((luan[0]==1)&&(luan[1]>=4))
                                        {
                                                luan[0]=2;
                                                luan[1]=3;
                                        }
                                        else if((luan[0]==2)&&(luan[3]==3))
                                        {
                                                luan[0]=luan[1]=0;
                                        }
                                }
                                        break;
                                case(0x02):
                                        if((luan[0]==0)||(luan[0]==1))
                                        {
                                                if(luan[1]<9)
                                                {
                                                        luan[1]=luan[1]+1;
                                                }
                                                else if(luan[1]==9)
                                                {
                                                        luan[1]=0;
                                                }
                                        }
                                        else if(luan[0]==2)
                                        {
                                                if(luan[1]<3)
                                                {
                                                        luan[1]=luan[1]+1;
                                                }
                                                else if(luan[1]==3)
                                                {
                                                        luan[0]=luan[1]=0;
                                                }
                                        }
                                        break;
                                case(0x04):
                                        if((luan[2]>=0)&&(luan[2]<=4))
                                        {
                                                luan[2]=luan[2]+1;
                                        }
                                        else if(luan[2]==5)
                                        {
                                                luan[2]=0;
                                        }
                                        break;
                                case(0x08):
                                        if(luan[3]<9)
                                        {
                                                luan[3]=luan[3]+1;
                                        }
                                        else if((luan[3]==9))
                                        {
                                                luan[3]=0;
                                        }
                                        else if((luan[3]==9)&&luan[2]==5)
                                        {
                                                luan[2]=0;
                                                luan[3]=0;
                                        }
                                        break;
                                case(0x10):
                                        if((luan[4]>=0)&&(luan[4]<=4))
                                        {
                                                luan[4]=luan[4]+1;
                                        }
                                        else if(luan[4]==5)
                                        {
                                                luan[4]=0;
                                        }
                                        break;
                                case(0x20):
                                        if(luan[5]<9)
                                        {
                                                luan[5]=luan[5]+1;
                                        }
                                        else if((luan[5]==9))
                                        {
                                                luan[5]=0;
                                        }
                                        else if((luan[5]==9)&&luan[4]==5)
                                        {
                                                luan[4]=0;
                                                luan[5]=0;
                                        }
                                        break;
                        }
                }
                break;
                case(0xfe):
                {
                        v=0x01;
                        a=z;
                        for(;a>1;a--)
                        {
                                v=v<<1;
                        }
                        switch(v)
                        {
                                case(0x01):
                                {
                                        if((luan[0]==0))
                                        {
                                                luan[0]=2;
                                        }
                                        else if((luan[0]<3)&&(luan>0))
                                        {
                                                luan[0]=luan[0]-1;
                                        }
                                }
                                        break;
                                case(0x02):
                                        if((luan[1]<=9)&&(luan[1]!=0))
                                        {
                                                luan[1]=luan[1]-1;
                                        }
                                        else if(luan[1]==0)
                                        {
                                                luan[1]=9;
                                        }
                                        break;
                                case(0x04):
                                        if((luan[2]<=5)&&(luan[2]!=0))
                                        {
                                                luan[2]=luan[2]-1;
                                        }
                                        else if(luan[2]==0)
                                        {
                                                luan[2]=5;
                                        }
                                        break;
                                case(0x08):
                                        if((luan[3]<=9)&&(luan[3]!=0))
                                        {
                                                luan[3]=luan[3]-1;
                                        }
                                        else if((luan[3]==0))
                                        {
                                                luan[3]=9;
                                        }
                                        break;
                                case(0x10):
                                        if((luan[4]<=5)&&(luan[4]!=0))
                                        {
                                                luan[4]=luan[4]-1;
                                        }
                                        else if(luan[4]==0)
                                        {
                                                luan[4]=5;
                                        }
                                        break;
                                        break;
                                case(0x20):
                                        if((luan[5]<=9)&&(luan[5]!=0))
                                        {
                                                luan[5]=luan[5]-1;
                                        }
                                        else if((luan[5]==0))
                                        {
                                                luan[5]=9;
                                        }
                                        break;
                        }
                }
                break;
        }
}
int main()
{
        TMOD=0x01;
        TH0=0x0b;
        TL0=0xdc;
        IE=0xff;
        TR0=1;
        IT0=1;
        while(1)
        {
                if(flickerflag!=0)
                {TR0=0;}
                if(flickerflag==0)
                {TR0=1;}
                for(m=1;m<11;m++)
                {
                        for(a=1;a<7;a++)
                        {
                                P1=duan[a-1];
                                 if(a==2||a==4)
                                {
                                        P0=SegCode[luan[a-1]]|0x80;
                                }
                                else 
                                        P0=SegCode[luan[a-1]];
                                delay(50);
                        }
                }
                if(flickerflag!=0)
                {
                        for(m=1;m<11;m++)
                        {
                                for(a=1;a<7;a++)
                                {
                                      if(a==z)
                                      {
                                              P1=0xff;
                                              delay(50);
                                      }
                                      else
                                      {
                                        P1=duan[a-1];
                                         if(a==2||a==4)
                                        {
                                                P0=SegCode[luan[a-1]]|0x80;
                                        }
                                        else 
                                                P0=SegCode[luan[a-1]];
                                        delay(500);
                                        }
                                }
                        }
                }
        }
}
void INT0_IRQHander() interrupt 0
{
        keycontrol(keyscan()); 
}
void T1_hander() interrupt 1
{
        TR0=0;
        TH0=0x0b;
        TL0=0xdc;
        TR0=1;
        y++;
        if(y>=16)
        {
                y=0;
                if(luan[5]<9)
                {
                        luan[5]++;
                }
                else if((luan[4]<5)&&(luan[5]==9))
                {
                        luan[4]++;
                        luan[5]=0;
                }
                else if((luan[3]<9)&&(luan[4]==5)&&(luan[5]==9))
                {
                        luan[3]++;
                        luan[4]=luan[5]=0;
                }
                else if((luan[2]<5)&&(luan[3]==9)&&(luan[4]==5)&&(luan[5]==9))
                {
                        luan[2]++;
                        luan[3]=luan[4]=luan[5]=0;
                }
                else if((luan[0]<2)&&(luan[1]<9)&&(luan[2]==5)&&(luan[3]==9)&&(luan[4]==5)&&(luan[5]==9))
                {
                        luan[1]++;
                        luan[2]=luan[3]=luan[4]=luan[5]=0;
                }
                else if((luan[0]<2)&&(luan[1]==9)&&(luan[2]==5)&&(luan[3]==9)&&(luan[4]==5)&&(luan[5]==9))
                {
                        luan[0]++;
                        luan[1]=luan[2]=luan[3]=luan[4]=luan[5]=0;
                }
                else if((luan[0]==2)&&(luan[1]<3)&&(luan[2]==5)&&(luan[3]==9)&&(luan[4]==5)&&(luan[5]==9))
                {
                        luan[1]++;
                        luan[2]=luan[3]=luan[4]=luan[5]=0;
                }
                else if((luan[0]==2)&&(luan[1]==3)&&(luan[2]==5)&&(luan[3]==9)&&(luan[4]==5)&&(luan[5]==9))
                {
                        luan[0]=luan[1]=luan[2]=luan[3]=luan[4]=luan[5]=0;
                }
        }
}