#include<pic.h>
#include<stdio.h>

char arr[10];
char adc[10];


#define rs RC0
#define rw RC1
#define en RC2

int adc0();
int adc1();
void display(int x,int y);
void delay();





void main()
{
TRISC=0X00;
TRISB=0X00;
	
ADCS1=0;      //CLOCK CONVERSATION
ADCS0=0;

ADON=1;	     //AD CONVERSATION ON

ADFM=1;      //RIGHT JUSTIFY
ADCS2=0;

PCFG3=0;     //ALL ANOLOG INPUT
PCFG3=0;
PCFG3=0;
PCFG3=0;

display(0x0e,0);
display(0x38,0);
	
while(1)
{
	//*********************
	
int a;	
a=adc0();      //result 0
sprintf(arr,"%04d",a);

display(0x80,0);
for(int i=0;arr[i]!='\0';i++)
{
display(arr[i],1);
}

  //*******************
  
display(0xc0,0);

int b;
b=adc1();     //result 1
sprintf(adc,"%04d",b);

for(int j=0;adc[j]!='\0';j++)
{
display(adc[j],1);
}

  //****************
	
}	
	
}

int adc0()
{
int low0;
int high0;
int result0;	
	
//CHANNEL 0
 CHS2=0;
 CHS1=0;
 CHS0=0;
 
 GODONE=1;
 while(GODONE==1); //WAIT HERE
 low0=ADRESL;
 high0=ADRESH;
 result0=low0|(high0<<8);
 return(result0);
 }
 
 
 int adc1()
{
int low1;
int high1;
int result1;	
	
 //CHANNEL 1
 CHS2=0;
 CHS1=0;
 CHS0=1;
 
 GODONE=1;
 while(GODONE==1); //WAIT HERE
 low1=ADRESL;
 high1=ADRESH;
 result1=low1|(high1<<8);
 return(result1);
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
int k;
for(k=0;k<10000;k++);	
}