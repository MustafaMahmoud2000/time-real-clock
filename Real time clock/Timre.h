/*
 * Timre.h
 *
 * Created: 11/15/2023 12:58:38 AM
 *  Author: DELL
 */ 


#ifndef TIMRE_H_
#define TIMRE_H_

void TIMER_CTC_INIT(void);
void TIMER_WAVA_NONPWM(void);
void TIMER_PWM_phase_correct(void);
void TIMER2_overflow_interrupt(void);


#endif /* TIMRE_H_ */