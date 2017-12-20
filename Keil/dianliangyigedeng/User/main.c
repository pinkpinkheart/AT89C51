#include <reg51.h>
sbit led=P0^1;
sbit m=P2^1;
int main()
{
        while(1)
        {
               led=0;
                m=1;
        }
}