/*
 *	Timing.h
 *
 *	Author: Andrew D. Horchler, adh9 @ case.edu
 *	Created: 2-12-15, modified: 5-8-16
 */
 
#include "Energia.h"
 
#ifndef TIMING_H_
#define TIMING_H_
#if defined(__cplusplus)
extern "C" {
#endif

/*
 *	Elapsed time in microseconds
 */
static unsigned long usElapsed(void)
{
  unsigned long t_prv;
  static unsigned long t_now = 0;
  static int isInit = 1;
  
  if (isInit) {
    isInit = 0;
    t_now = micros();
    
    return 0;
  } else {
    t_prv = t_now;
    t_now = micros();
    
    return t_now - t_prv;
  }
}

/*
 *	Elapsed time in milliseconds
 */
static unsigned long msElapsed(void)
{
  unsigned long t_prv;
  static unsigned long t_now = 0;
  static int isInit = 1;
  
  if (isInit) {
    isInit = 0;
    t_now = millis();
    
    return 0;
  } else {
    t_prv = t_now;
    t_now = millis();
    
    return t_now - t_prv;
  }
}

#if defined(__cplusplus)
}
#endif

#endif /* TIMING_H_ */
