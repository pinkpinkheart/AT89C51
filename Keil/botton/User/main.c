#include <reg51.h>
int main()
{
	int i;
	switch(P2)
	{
		case(0x7f):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0x7f);break;
		case(0xbf):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xbf);break;
		case(0xdf):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xdf);break;
		case(0xef):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xef);break; 
		case(0xf7):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xf7);break;
		case(0xfb):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xfb);break;
		case(0xfd):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xfd);break;
		case(0xfe):for(i=1000;i>0;i--);P0=~P2^P0;while (P2==0xfe);break;
	}
	return 0;
}


