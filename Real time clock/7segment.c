#include "DIO.H"
#define cc
void seven_seg_init(char port)
{
vDIO_SET_PORT(port,0Xff);
	
}
void seven_seg_write(char port,char number)
{
unsigned char arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
vDIO_WRITE_PORT(port,arr[number]);
}
void seven_seg_bcd_init(unsigned char port)
{
	vDIO_SET_BIT_DIR(port,0,1);
	vDIO_SET_BIT_DIR(port,1,1);
	vDIO_SET_BIT_DIR(port,2,1);
	vDIO_SET_BIT_DIR(port,3,1);
}
void seven_seg_bcd_write_low(unsigned char port,unsigned char value)
{
	vDIO_WRITE_LOW_NIBBLE(port, value);
	
}
void seven_seg_bcd_write_high(unsigned char port,unsigned char value)
{
	
	vDIO_WRITE_HIGH_NIBBLE(port, value);
}
