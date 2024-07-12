/*
 * matrix display.cpp
 *
 * Created: 18/06/2024 2:29:11 pm
 * Author : Lokesh
 */ 

#define F_CPU 16000000UL
#include<avr/io.h>
#include "pinconfig.h"
#include "timerr.h"

void Display2(void);
void Display3(void);
void Display4(void);

	long long A[]={0x60,0xD8,0xF0,0x64,0xB4,0x3C,0xE0,0xFC,0xE4,0xFC};
	
	long long B[]={0x00,0x02,0x02,0x02,0x02,0x02,0x00,0x02,0x02,0x00};
		
	int n=0;


int main(void)
{
	DDRB = 0XFF;
	DDRC = 0XFF;  //{Initialize PORT B AND PORT C as Output }// 
	DDRD = 0X00;  //{Initialize PORTD as Input}//;
	

	
	
/*
		while(1)
		{
			for(int i =0;i<8;i++)
			{
				SEGA=A[i];
				SEGB=B[i];			
				SEGB |= DIGIT1;
				SEGB |= DIGIT2;
				milsecdelay(1000);
			}
		}
	*/

	while (1)
	{
		
			SEGA=A[0];
			SEGB=B[0];
			SEGB |=DIGIT1;  // Initialize all the digits to display 0000// 
			SEGB |=DIGIT2;
			SEGB |=DIGIT3;
			SEGB |=DIGIT4;
			for(int i=0;i<3;i++)
				{
					SEGA=A[i];
					SEGB=B[i];
					SEGB |=DIGIT1; //Setting up the hour digit MSB
					if(i==2)
					{
						n=1;
					}
					Display2(); 

				}
			
	}
	
}

void Display2(void)
{
	switch(n)
	{
		
		case 0:
		for(int j=0;j<11;j++)
		{
			SEGA=A[j];
			SEGB=B[j];
			SEGB |=DIGIT2;  //Setting up the hour digit LSB
			Display3();
		}
		case 1:
		for(int j=0;j<5;j++)
		{
			SEGA=A[j];
			SEGB=B[j];
			SEGB |=DIGIT2;  //Setting up the hour digit LSB
			Display3();
		}
	}
}


void Display3(void)
{
	for(int k=0;k<7;k++)
	{
		SEGA=A[k];
		SEGB=B[k];
		SEGB |=DIGIT3;  //Setting up the minute digit MSB
		Display4();
	}
}

void Display4(void)
{
	for(int l=0;l<11;l++)
	{
		SEGA=A[l];
		SEGB=B[l];
		SEGB |=DIGIT4;  //Setting up the minute digit LSB
		milsecdelay(1000);
	}
}
