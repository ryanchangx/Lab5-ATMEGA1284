/*	Author: rchan123
 *  Partner(s) Name: none
 *	Lab Section: 023
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: Same as Lab 3 EX 2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	/* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char lowFuel = 0x00;
	while (1) {
		tmpA = ~(PINA) & 0x0F;
		tmpC = 0x00;
		if(tmpA > 12){
			tmpC = tmpC | 0x01;
		}
		if(tmpA > 9){
			tmpC = tmpC | 0x02;
		}
		if(tmpA > 6){
			tmpC = tmpC | 0x04;
		}
		if(tmpA > 4){
			tmpC = tmpC | 0x08;
		}
		if(tmpA > 2){
			tmpC = tmpC | 0x10;
		}
		if(tmpA > 0){
			tmpC = tmpC | 0x20;
		}
		if(tmpA <= 4){
			lowFuel = 0x40;
		}
		else{
			lowFuel = 0x00;
		}
		PORTC = tmpC | lowFuel;
	}
	return 0;
}
