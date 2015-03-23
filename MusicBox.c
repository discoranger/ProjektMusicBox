/*
 * HelloPi.c
 *
 *  Created on: 10.03.2015
 *      Author: matthias
 */

#include <stdio.h>
#include <wiringPi.h>				// pifoo
#include <softTone.h>
#include <pthread.h>
#include <unistd.h>
#include "functions/App_defines.h"
#include "functions/Melody_Thread.h"

int main(void){
	if (wiringPiSetup() == -1)
		return 1;
    wiringPiISR (PIN_0, INT_EDGE_FALLING, &MusicISR);
	while(1){
		pause();
	}
	return 0;
}

