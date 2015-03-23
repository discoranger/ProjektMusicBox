/*
 * Melody_Thread.c
 *
 *  Created on: 19.03.2015
 *      Author: matthias
 */

#include <stdio.h>
#include <pthread.h>
#include <softTone.h>
#include <wiringPi.h>
#include "Melody_Thread.h"
#include "App_defines.h"

int Melody_Number = -1;
int Melody_Length;
int thread_running = 0;
int Melody_Length_All[MELODY_NUMBER] = {STAR_WARS_LENGTH, INDY_LENGTH};

int Melodies [MELODY_NUMBER][MELODY_CHANELS][MELODY_LENGTH_MAX]=
{	{	STAR_WARS_FREQ,
		STAR_WARS_TIME
	},
	{	INDY_FREQ,
		INDY_TIME
	}
};

pthread_t MusicThread;


/*********************************************************
 * Thread to play melody chosen by the global Melody_Number
 */
//static PI_THREAD(PlayMusic){
void *PlayMusic(){
	if (Melody_Number == -1){
		pthread_exit(NULL);
	}
	int i;
	softToneCreate(PIN_7);
	while(1){
		for(i = 0; i < Melody_Length; i++){
			softToneWrite(PIN_7, Melodies[Melody_Number][0][i]);
			delay(Melodies[Melody_Number][1][i]);
		}
	}
	pthread_exit(NULL);
}

void MusicISR(void){
	if(thread_running != 0){
		pthread_cancel (MusicThread);
		//pthread_join   (MusicThread, NULL);
		softToneWrite(PIN_7, 0);
		thread_running = 0;
	}
	switch (Melody_Number){
	case (MELODY_NUMBER - 1):
		Melody_Number = - 1;
		pthread_cancel (MusicThread);
		softToneStop(PIN_7);
		break;
	default:
		Melody_Number++;
		Melody_Length = Melody_Length_All[Melody_Number];
		pthread_create(&MusicThread, NULL, PlayMusic, NULL);
		thread_running = 1;
		break;
	}
}






