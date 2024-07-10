/*
 * timerr.h
 *
 * Created: 25/06/2024 9:04:23 am
 *  Author: Lokesh
 */ 


#ifndef TIMERR_H_
#define TIMERR_H_

long long count;

void milsecdelay(long time)
{
	count = (time/64) * 1000;
	TCNT1=0;
	OCR1A=(count-1);
	TCCR1A = 0X00;
	TCCR1B = 0X0D;
	while((TIFR &(1<<OCF1A))==0);
	TCCR1B = 0;
	TIFR = (1<<OCF1A);
}



#endif /* TIMERR_H_ */