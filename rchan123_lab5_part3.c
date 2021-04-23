/*	Author: ryan
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *  https://drive.google.com/file/d/1GNdIGbiOoj-vq0LWBBu2aHxPoRO0_Soh/view?usp=sharing
 * 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum STATES{WAIT, DOWN, UP} STATE;
const int order[25] = {6,5,4,3,2,1,2,3,4,5,7,8,9,10,9,8,7,11,12,11,12,13,0,13,0};
int i = 0;

void tick(){
	unsigned char button = ~PINA & 0x01;
	unsigned char led = 0x00;
	switch(STATE){
		case WAIT:
			STATE = (button)? DOWN : WAIT;
			break;
		case DOWN:
			STATE = UP; // won't be concerned with button being pressed within the same tick, not reasonable for human
			break;
		case UP:
			STATE = (button)? UP : WAIT;
			break;
		default:
			STATE = WAIT;
			break;
	}
	switch(STATE){
		case WAIT:
			break;
		case DOWN:
			if(order[i] == 0)
				led = 0x00;
			else if(order[i] == 1)
				led = 0x01;
			else if(order[i] == 2)
				led = 0x02;
			else if(order[i] == 3)
				led = 0x04;
			else if(order[i] == 4)
				led = 0x08;
			else if(order[i] == 5)
				led = 0x10;
			else if(order[i] == 6)
				led = 0x20;
			else if(order[i] == 7)
				led = 0x28;
			else if(order[i] == 8)
				led = 0x14;
			else if(order[i] == 9)
				led = 0x0A;
			else if(order[i] == 10)
				led = 0x05;
			else if(order[i] == 11)
				led = 0x38;
			else if(order[i] == 12)
				led = 0x07;
			else if(order[i] == 13)
				led = 0x3F;
			++i;
			if(i == 25){
				i = 0;
			}
			PORTB = led;
			break;
		case UP: 
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	STATE = WAIT;
    while (1) {
		tick();
    }
    return 1;
}
