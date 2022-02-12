#include <REGX51.H>
#include <intrins.h>

void Delay(unsigned int ms)
{
	unsigned char i, j;
	while(ms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
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


void Nixie(unsigned char Location,Number)
{
	switch(Location)		
	{
		case 1:	P3_4 = 1;
	          P3_5 = 0;
		        break;
		case 2: P3_4 = 0;
	          P3_5 = 1;
		        break;
	}
	P2 = NixieTable[Number];	
	Delay(1);				
	P2 = 0x00;			
}

void main(){

	P3_0 = 1;
	P3_1 = 0;
	while(1){
	   Nixie(1,1);	
		 Nixie(2,3);	
	}
		
}