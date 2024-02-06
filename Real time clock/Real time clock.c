/*
 * Real_time_clock.c
 *
 * Created: 12/1/2023 3:02:24 AM
 *  Author:mustafa mahmoud saad hamada
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timre.h"
#include "7segment.h"
#include "LCD 8BIT.h"
#include "keybad.h"
#include "EEPROM.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
volatile unsigned char seconds=0;
unsigned int day=0,month=0,year=0,flag=0,flag1=0,min=0,hou=0,minutes=0,hours=0;
unsigned char digit1,digit2,READ,digit3,digit4;
volatile unsigned char sec=0;
int main(void)
{
	keypad_vinit();
	LCD_INIT();
	seven_seg_init('B');
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_SEND_CMD(0x0c);
	

     LCD_SEND_STRING("SET TIME (1)");
// 	LCD_MOVE_CURSOR(2,1);
// 	LCD_SEND_STRING("SET DATA (2)");
	_delay_ms(500);
	TIMER2_overflow_interrupt();
	
   while(1)
   { 
	   	 L7:
		READ=keybad_u8read_press();
		if(READ!=notpassed)
		{
			if(READ =='1')
			{
				L1:
				LCD_clear_screen();
				LCD_SEND_STRING("HOURS:--");
				LCD_MOVE_CURSOR(1,7);
				_delay_ms(150);
				do
				{
					digit1=keybad_u8read_press();
					
				}while(digit1==notpassed);
				LCD_SEND_CHAR(digit1);
				_delay_ms(150);
				do
				{
					digit2=keybad_u8read_press();
					
				}while(digit2==notpassed);
				LCD_SEND_CHAR(digit2);
				_delay_ms(150);
				hours=(digit2-48)+10*(digit1-48);
				if(hours>24)
				{
					LCD_clear_screen();
					LCD_SEND_STRING("enter hour again");
					LCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("between 01 to 24");
					_delay_ms(300);
					goto L1;
				}
				L2:
				LCD_clear_screen();
				LCD_SEND_STRING("MINUTES:--");
				LCD_MOVE_CURSOR(1,9);
				_delay_ms(150);
				do
				{
					digit1=keybad_u8read_press();
					
				}while(digit1==notpassed);
				LCD_SEND_CHAR(digit1);
				_delay_ms(150);
				do
				{
					digit2=keybad_u8read_press();
					
				}while(digit2==notpassed);
				LCD_SEND_CHAR(digit2);
				_delay_ms(150);
				minutes=(digit2-48)+10*(digit1-48);
				if(minutes>60)
				{
					LCD_clear_screen();
					LCD_SEND_STRING("enter minu again");
					LCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("between 01 to 60");
					_delay_ms(300);
					goto L2;
				}
				L3:
				LCD_clear_screen();
				LCD_SEND_STRING("SECONDS:--");
				LCD_MOVE_CURSOR(1,9);
				_delay_ms(150);
				
				do
				{
					digit1=keybad_u8read_press();
					
				}while(digit1==notpassed);
				LCD_SEND_CHAR(digit1);
				_delay_ms(200);
				do
				{
					digit2=keybad_u8read_press();
					
				}while(digit2==notpassed);
				LCD_SEND_CHAR(digit2);
				_delay_ms(150);
				seconds=(digit2-48)+10*(digit1-48);
				if(seconds>60)
				{
					LCD_clear_screen();
					LCD_SEND_STRING("enter sec again");
					LCD_MOVE_CURSOR(2,1);
					LCD_SEND_STRING("between 01 to 60");
					_delay_ms(300);
					goto L3;
				}
				flag=1;
			}	
			
			
			
					
// 			else if(READ=='2')
// 			{
				
// 				L4:
// 				LCD_clear_screen();
// 				LCD_SEND_STRING("MONTHS:--");
// 				LCD_MOVE_CURSOR(1,8);
// 				_delay_ms(150);
// 				do
// 				{
// 					digit1=keybad_u8read_press();
// 							
// 				}while(digit1==notpassed);
// 				LCD_SEND_CHAR(digit1);
// 				_delay_ms(200);
// 				do
// 				{
// 					digit2=keybad_u8read_press();
// 							
// 				}while(digit2==notpassed);
// 				LCD_SEND_CHAR(digit2);
// 				_delay_ms(150);
// 				month=(digit2-48)+10*(digit1-48);
// 				if(month>12)
// 				{
// 					LCD_clear_screen();
// 					LCD_SEND_STRING("enter mon again");
// 					LCD_MOVE_CURSOR(2,1);
// 					LCD_SEND_STRING("between 01 to 12");
// 					_delay_ms(300);
// 					goto L4;
// 				}
// 				L5:
// 				LCD_clear_screen();
// 				LCD_SEND_STRING("DAYS:--");
// 				LCD_MOVE_CURSOR(1,6);
// 				_delay_ms(200);
// 				do
// 				{
// 					digit1=keybad_u8read_press();
// 							
// 				}while(digit1==notpassed);
// 				LCD_SEND_CHAR(digit1);
// 				_delay_ms(150);
// 				do
// 				{
// 					digit2=keybad_u8read_press();
// 							
// 				}while(digit2==notpassed);
// 				LCD_SEND_CHAR(digit2);
// 				_delay_ms(200);
// 				day=(digit2-48)+10*(digit1-48);
// 				if(day>30)
// 				{
// 					LCD_clear_screen();
// 					LCD_SEND_STRING("enter days again");
// 					LCD_MOVE_CURSOR(2,1);
// 					LCD_SEND_STRING("between 01 to 30");
// 					_delay_ms(300);
// 					goto L5;
// 				}
// 				LCD_clear_screen();
// 				LCD_SEND_STRING("YEARS:----");
// 				LCD_MOVE_CURSOR(1,7);
// 				_delay_ms(150);
// 				do
// 				{
// 					digit1=keybad_u8read_press();
// 							
// 				}while(digit1==notpassed);
// 				LCD_SEND_CHAR(digit1);
// 				_delay_ms(150);
// 				do
// 				{
// 					digit2=keybad_u8read_press();
// 							
// 				}while(digit2==notpassed);
// 				LCD_SEND_CHAR(digit2);
// 				_delay_ms(150);
// 				do
// 				{
// 					digit3=keybad_u8read_press();
// 							
// 				}while(digit3==notpassed);
// 				LCD_SEND_CHAR(digit3);
// 				_delay_ms(150);
// 				do
// 				{
// 					digit4=keybad_u8read_press();
// 							
// 				}while(digit4==notpassed);
// 				LCD_SEND_CHAR(digit4);
// 				_delay_ms(150);
// 				year=(digit1-48)*1000+(digit2-48)*100+(digit3-48)*10+(digit4-48);
// 				LCD_clear_screen();
// 				
/*    	}*/
			else
			{
				LCD_clear_screen();
				LCD_SEND_STRING("WRONG NUMBER");
				_delay_ms(300);
				goto L7;
			}
			LCD_clear_screen();
			 LCD_SEND_STRING("(1)set time");
			 
		
		}	
		
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		CLEAR_BIT(PORTC,5);
		seven_seg_write('B',seconds%10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,5);
		CLEAR_BIT(PORTC,4);
		seven_seg_write('B',seconds/10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLEAR_BIT(PORTC,3);
		seven_seg_write('B',minutes%10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLEAR_BIT(PORTC,2);
		seven_seg_write('B',minutes/10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLEAR_BIT(PORTC,1);
		seven_seg_write('B',hours%10);
		_delay_ms(5);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLEAR_BIT(PORTC,0);
		seven_seg_write('B',hours/10);
		_delay_ms(5); 
		
		
		
		
// 		LCD_MOVE_CURSOR(1,1);
// 		LCD_SEND_STRING("Time:");
// 		LCD_MOVE_CURSOR(1,6);
// 		LCD_SEND_CHAR(hours/10+48);
// 		LCD_SEND_CHAR(hours%10+48);
// 		LCD_SEND_STRING(":");
// 		LCD_SEND_CHAR(minutes/10+48);
// 		LCD_SEND_CHAR(minutes%10+48);
// 		LCD_SEND_STRING(":");
// 		LCD_SEND_CHAR(seconds/10+48);
// 		LCD_SEND_CHAR(seconds%10+48);
// 		LCD_MOVE_CURSOR(2,1);
// 		LCD_SEND_STRING("Data:");
// 		LCD_MOVE_CURSOR(2,6);
// 		LCD_SEND_CHAR(month/10+48);
// 		LCD_SEND_CHAR(month%10+48);
// 		LCD_SEND_STRING("/");
// 		LCD_SEND_CHAR(day/10+48);
// 		LCD_SEND_CHAR(day%10+48);
// 		LCD_SEND_STRING("/");
// 		LCD_SEND_CHAR((year/1000) +48);
// 		LCD_SEND_CHAR(((year/100) % 10)+48);
// 		LCD_SEND_CHAR(((year/10) % 10)+48);
// 		LCD_SEND_CHAR((year%10) +48);
		if(seconds>=60)
		{
			seconds=0;
			minutes++;
		}
		if (minutes>=60)
		{
			minutes=0;
			hours++;
		}
		
// 		if(flag==1&& hours<=12)
// 		{
// 			LCD_MOVE_CURSOR(1,15);
// 			LCD_SEND_STRING("AM");
// 		}
// 		else if(hours>= 13 && hours<=24 && flag==1)
// 		{
// 			day++;
// 			LCD_MOVE_CURSOR(1,15);
// 			LCD_SEND_STRING("PM");
// 			hours=hours-12;
// 			flag=0;
// 		}
		
		if (day>=31)
		{
			day=1;
			month++;
		}
		if (month>=13)
		{
			month=1;
			year++;		
		}
							 														
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds++;
	sec++;
}