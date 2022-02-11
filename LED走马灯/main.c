#include <REGX51.H>
#include <intrins.h>

void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(){

	while(1){
		P1 = 0x01;
		Delay500ms();
		P1 = 0x02;
		Delay500ms();
		P1 = 0x04;
		Delay500ms();
	}
		
}