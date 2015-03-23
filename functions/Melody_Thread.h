/*
 * Melody_Thread.h
 *
 *  Created on: 19.03.2015
 *      Author: matthias
 */

#ifndef FUNCTIONS_MELODY_THREAD_H_
#define FUNCTIONS_MELODY_THREAD_H_



#endif /* FUNCTIONS_MELODY_THREAD_H_ */

#include <softTone.h>
#include <pthread.h>

#define STAR_WARS_LENGTH 16
#define INDY_LENGTH 39
#define d 145
#define e 165
#define f 175
#define g 196
#define a 220
#define h 247
#define c_ 262
#define d_ 294
#define e_ 330
#define f_ 349
#define g_ 392
#define PAUSE 0
#define BPM 60

#define MELODY_NUMBER 2
#define MELODY_LENGTH_MAX 64
#define MELODY_CHANELS 2

#define STAR_WARS_FREQ {g,d_,c_,h,a,g_,d_,c_,h,a,g_,d_,c_,h,c_,a}
#define STAR_WARS_TIME {500,500,83,83,83,500,250,83,83,83,500,250,83,83,83,500}

#define INDY_FREQ {e,f,g,c_,PAUSE,d,e,f,g,a,h,f_,PAUSE,a,h,c_,d_,e_,e,f,g,c_,PAUSE,d_,e_,f_,g,g,e_,d_,g,e_,d_,g,e_,d_,g,e_,d}
#define INDY_TIME {375,125,250,1000,250,375,125,1500,375,125,250,1000,250,375,125,500,500,500,375,125,250,1000,250,375,125,1500,375,125,500,375,125,500,375,125,500,375,125,250,250}

extern int Melody_Number;
extern int Melody_Length;

extern void MusicISR(void);
