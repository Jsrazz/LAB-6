/*
 * Robot.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15James.Rasmussen
 */
#include "Robot.h"
#include <msp430.h>




void initRobot(){
	P1DIR |= BIT1;
	P1SEL |= BIT1;

	P1DIR |= BIT2;
	P1SEL |= BIT2;

	P2DIR |= BIT0;
	P2SEL |= BIT0;

	P2DIR |= BIT1;
	P2SEL |= BIT1;
}

void initTimer(){
	TA0CTL &= ~(MC1|MC0);
	TA1CTL &= ~ (MC1|MC0);

	TA0CTL |= TACLR;
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;
	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;
	TA1CCR0 = 100;
	TA0CCR1 = 50;
	TA1CCR1 = 50;

	TA0CCTL1 |= OUTMOD_5;
	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_5;


	TA0CTL |= MC0;
	TA1CTL |= MC0;
}
void rightFor(){
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;


	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;

	TA0CTL |= MC0; // count up
	TA1CTL |= MC0;

}
void leftFor(){

	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA0CCTL0 |= OUTMOD_5; // set TACCTL1 to Reset / Set mode
	TA0CCTL1 |= OUTMOD_7;
	TA0CTL |= MC0;
	TA1CTL |= MC0;
}
void rightBack(){

	TA1CTL &= ~MC0;
	TA1CTL &= ~MC1;

	TA1CCTL0 &= ~OUTMOD_4; // set TACCTL1 to Reset / Set mode
	TA1CCTL0 &= ~OUTMOD_5;
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL1 &= ~OUTMOD_5;
	TA1CCTL0 |= OUTMOD_4; // set TACCTL1 to Reset / Set mode
	TA1CCTL1 |= OUTMOD_5;
	TA0CTL |= MC0;
	TA1CTL |= MC0;



}
void leftBack(){
	TA0CTL &= ~MC0;
	TA0CTL &= ~MC1;

	TA0CCTL0 &= ~OUTMOD_4; // set TACCTL1 to Reset / Set mode
	TA0CCTL0 &= ~OUTMOD_5;
	TA0CCTL1 &= ~OUTMOD_7;
	TA0CCTL1 &= ~OUTMOD_5;
	TA0CCTL0 |= OUTMOD_4; // set TACCTL1 to Reset / Set mode
	TA0CCTL1 |= OUTMOD_5;
	TA0CTL |= MC0;
	TA1CTL |= MC0;

}

void moveForward(){
	rightFor();
	leftFor();

}

void moveBackwards(){

	rightBack();
	leftBack();
}
void turnLeft(){
	rightFor();
	leftBack();

}

void turnRight(){
	rightBack();
	leftFor();



}
