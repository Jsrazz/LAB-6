#include <msp430.h> 
#include "Robot.h"
/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initRobot();
	initTimer();
	while(1){
		moveForward();
		_delay_cycles(1000000);
		moveBackwards();
		_delay_cycles(1000000);
		turnLeft();
		_delay_cycles(250000);
		turnRight();
		_delay_cycles(400000);
		turnLeft();
		_delay_cycles(750000);
		turnRight();
		_delay_cycles(800000);


	}

	return 0;
}
