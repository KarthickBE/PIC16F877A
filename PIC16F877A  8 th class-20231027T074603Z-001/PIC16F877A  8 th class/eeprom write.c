#include<pic.h>

void main()
{
EEADR=0X00;
EEDATA='a';
EEPGD=0;
WREN=1;

EECON2=0X55;
EECON2=0XAA;

WR=1;
WREN=0;

while(WR==1);


while(1)
{
	

	
}	
	
}	
	
	
	
	
	
	
