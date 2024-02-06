#include "LCD 8BIT.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void LCD_INIT(void)
{
	_delay_ms(200);
	#if defined eight_bit_mode
	vDIO_SET_BIT_DIR(LCD_DATA,0,1);
	vDIO_SET_BIT_DIR(LCD_DATA,1,1);
	vDIO_SET_BIT_DIR(LCD_DATA,2,1);
	vDIO_SET_BIT_DIR(LCD_DATA,3,1);
	vDIO_SET_BIT_DIR(LCD_DATA,4,1);
	vDIO_SET_BIT_DIR(LCD_DATA,5,1);
	vDIO_SET_BIT_DIR(LCD_DATA,6,1);
	vDIO_SET_BIT_DIR(LCD_DATA,7,1);
	vDIO_SET_BIT_DIR(LCD_CONTROL,EN,1);
	vDIO_SET_BIT_DIR(LCD_CONTROL,RS,1);
	vDIO_SET_BIT_DIR(LCD_CONTROL,WR,1);
	vDIO_WRITE_BIT(LCD_CONTROL,WR,0);
	LCD_SEND_CMD(RET_HOME);
	_delay_ms(10);
	LCD_SEND_CMD(EIGHT_BIT);
	_delay_ms(1);
	LCD_SEND_CMD(DISPLAY_CURSOR);
	_delay_ms(1);
	//LCD_SEND_CMD(CLR_SCREEN);
	_delay_ms(1);
	LCD_SEND_CMD(ENTRY_MODE);
	_delay_ms(1);
	#elif defined four_bit_mode
	vDIO_SET_BIT_DIR(LCD_DATA,4,1);
	vDIO_SET_BIT_DIR(LCD_DATA,5,1);
	vDIO_SET_BIT_DIR(LCD_DATA,6,1);
	vDIO_SET_BIT_DIR(LCD_DATA,7,1);
	vDIO_SET_BIT_DIR(LCD_DATA,EN,1);
	vDIO_SET_BIT_DIR(LCD_DATA,RS,1);
	vDIO_SET_BIT_DIR(LCD_DATA,WR,1);
	vDIO_WRITE_BIT(LCD_DATA,WR,0);
	LCD_SEND_CMD(RET_HOME);
	_delay_ms(10);
	LCD_SEND_CMD(FOUR_BIT);
	_delay_ms(1);
	LCD_SEND_CMD(DISPLAY_CURSOR);
	_delay_ms(1);
	//LCD_SEND_CMD(CLR_SCREEN);
	_delay_ms(10);
	LCD_SEND_CMD(ENTRY_MODE);
	_delay_ms(1);
	#endif
	
}
void LCD_SEND_CHAR( char data)
{
	#if defined eight_bit_mode
	vDIO_WRITE_PORT(LCD_DATA,data);
	vDIO_WRITE_BIT(LCD_CONTROL,RS,1);
	LCD_ENABLE();
	#elif defined four_bit_mode
	vDIO_WRITE_HIGH_NIBBLE(LCD_DATA,data>>4);
	vDIO_WRITE_BIT(LCD_DATA,RS,1);
	LCD_ENABLE();
	vDIO_WRITE_HIGH_NIBBLE(LCD_DATA,data);
	vDIO_WRITE_BIT(LCD_DATA,RS,1);
	LCD_ENABLE();
	#endif
	_delay_ms(1);

}
static void LCD_ENABLE(void)
{
	vDIO_WRITE_BIT(LCD_DATA,EN,1);
	_delay_ms(2);
	vDIO_WRITE_BIT(LCD_DATA,EN,0);
	_delay_ms(2);
	
}
void LCD_SEND_CMD( char cmd)
{
	#if defined eight_bit_mode
	vDIO_WRITE_PORT(LCD_DATA,cmd);
	vDIO_WRITE_BIT(LCD_CONTROL,RS,0);
	LCD_ENABLE();
	_delay_ms(1);
	#elif defined four_bit_mode
	vDIO_WRITE_HIGH_NIBBLE(LCD_DATA,cmd>>4);
	vDIO_WRITE_BIT(LCD_DATA,RS,0);
	LCD_ENABLE();
	vDIO_WRITE_HIGH_NIBBLE(LCD_DATA,cmd);
	vDIO_WRITE_BIT(LCD_DATA,RS,0);
	LCD_ENABLE();
	#endif
	_delay_ms(1);
	
}
void LCD_clear_screen(void)
{
	LCD_SEND_CMD(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_SEND_STRING( char *data)
{
	while((*data)!='\0')
	{
		LCD_SEND_CHAR(*data);
		data++;
	}
}
void LCD_MOVE_CURSOR( char row, char colum)
{
	char val;
	if(row>2||row<1||colum>16||colum<1)
	{
		val=0x80;
	}
	else if(row==1)
	{
		val=0x80+(colum-1);
	}
	else if(row==2)
	{
		val=0xC0+(colum-1);
	}	
	
	LCD_SEND_CMD(val);
	_delay_ms(1);	 
}
		
 


