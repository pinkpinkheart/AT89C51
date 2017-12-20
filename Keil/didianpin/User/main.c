#include <reg51.h>
int main()
{
	int i,a;
	P0=0xfe;
	for(i=10000;i>0;i--);
	for(a=8;a>0;a--)
	{
		P0=~P0;
		P0=P0<<1;
		P0=~P0;
		for(i=10000;i>0;i--);
	}
	P0=0x7f;
	for(i=10000;i>0;i--);
	for(a=8;a>0;a--)
	{
		P0=~P0;
		P0=P0>>1;
		P0=~P0;
		for(i=10000;i>0;i--);
	}
	return 0;
}