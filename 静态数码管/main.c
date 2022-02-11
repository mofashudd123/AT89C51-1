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

unsigned char NixieTable[]={
0x3F,
0x06,
0x5B,
0x4F,
0x66,
0x6D,
0x7D,
0x07,
0x7F,
0x6F
};

void main(){

	while(1){
		int i;
		for(i=0;i<=9;i++){
			P1 = NixieTable[i];
			Delay500ms();
		}
	}
		
}