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

		while(1)
		{
			for(int i =0;i<8;i++)
			{
				SEGA=A[i];
				SEGB=B[i];			
				milsecdelay(1000);
			}
		}
		
}