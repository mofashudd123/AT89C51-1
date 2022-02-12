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
		case 1:	P3_5 = 0; P3_6 = 0; P3_7 = 0; break;
		case 2:	P3_5 = 1; P3_6 = 0; P3_7 = 0; break;
		case 3:	P3_5 = 0; P3_6 = 1; P3_7 = 0; break;
		case 4:	P3_5 = 1; P3_6 = 1; P3_7 = 0; break;
		case 5:	P3_5 = 0; P3_6 = 0; P3_7 = 1; break;
		case 6:	P3_5 = 1; P3_6 = 0; P3_7 = 1; break;
	}
	P2 = NixieTable[Number];	
	Delay(1);				
	P2 = 0x00;			
}

void main(){

	P3_0 = 1;
	P3_1 = 0;
	P1_5 = 0;
	P1_6 = 0;
	P1_7 = 1;

	while(1){
		 Nixie(1,0);	
		 Nixie(2,0);
		 Nixie(3,0);
		 Nixie(4,0);
		 Nixie(5,0);
		 Nixie(6,0);
	}
		
}