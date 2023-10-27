#include<pic.h>
#include<stdio.h>

#define rs RC0
#define rw RC1
#define en RC2

void display(int x,int y);
void delay();

int main()
{

int lowbyte;
int highbyte;
int result;
char arr[10];

TRISC=0x00;
TRISB=0x00;

ADCON0=0X01;
ADCON1=0X80;
display(0x0e,0);

while(1)
{
	GODONE=1;
	while(GODONE==1);
	lowbyte=ADRESL;
	highbyte=ADRESH;
	result=lowbyte|(highbyte<<8);
	delay();
	sprintf(arr,"%04d",result);     //need 4 num s0 04
    display(0x80,0);           
 
for(int i=0;arr[i]!='\0';i++)
	{
	display(arr[i],1);
	}
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
	
		
	
	