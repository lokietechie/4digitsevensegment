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


int main(void)
{
	DDRB = 0XFF;
	DDRD = 0XFF;
	DDRC = 0XFF;  //{Initialize PORT B AND PORT C as Output }// 
	
	long long A[]={0x60,0xD8,0xF0,0x64,0xB4,0x3C,0xE0,0xFC,0xE4,0xFC};
		
	long long B[]={0x00,0x02,0x02,0x02,0x02,0x02,0x00,0x02,0x02,0x00};
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
				SEGB |=DIGIT1;  //Setting up the hour digit MSB
				Display2(); 
			}
			
			void Display2();
			{
				for(int i=0;i<11;i++)
				{
					SEGA=A[i];
					SEGB=B[i];
					SEGB |=DIGIT2;  //Setting up the hour digit LSB
					Display3();
				}
			}
			
			void Display3();
			{
				for(int i=0;i<6;i++)
				{
					SEGA=A[i];
					SEGB=B[i];
					SEGB |=DIGIT3;  //Setting up the minute digit MSB
					Display4();
				}
			}
			
			void Display4();
			{
				for(int i=0;i<11;i++)
				{
					SEGA=A[i];
					SEGB=B[i];
					SEGB |=DIGIT4;  //Setting up the minute digit LSB
					milsecdelay(1000);
				}
			}
			
	}		
}
