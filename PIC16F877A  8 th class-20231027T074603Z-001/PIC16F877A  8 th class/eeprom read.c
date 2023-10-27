#include<pic.h>

#define rs RC0
#define rw RC1
#define en RC2

void display(int x,int y);
void delay();

void main()
{
TRISB=0X00;
TRISC=0X00;
int data;
EEADR=0X01;
EEPGD=0;
RD=1;
data=EEDATA;
display(0x0e,0);
display(data,1);


//EEADR=0X01;
//EEDATA='k';
//EEPGD=0;
//WREN=1;

//EECON2=0X55;
//EECON2=0XAA;

//WR=1;
//WREN=0;

//while(WR==1);

while(1)
{
	

	
}	
	
}	
	



void display(int x,int y)
{
PORTB=x;
rs=y;
rw=0;
en=1;
delay();
en=0;
}

void delay()
{
int i;
for(i=0;i<30000;i++);
}





	
	
	
	
