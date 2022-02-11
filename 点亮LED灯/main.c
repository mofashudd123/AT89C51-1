#include <REGX51.H>

/*
 LED为共阴级接法（高电平点亮）
 如果要点亮P1_0引脚的LED灯，
 则向P1_0输出高电平即可。
*/

void main(){
	
	P1_0 = 1;
	while(1){}
		
}
