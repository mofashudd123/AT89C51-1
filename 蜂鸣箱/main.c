#include <REGX51.H>

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

void main(){
	P1_0 = 0;
  while(1){
	 P1_0 = ~P1_0;
	 Delay(100);
	}
}