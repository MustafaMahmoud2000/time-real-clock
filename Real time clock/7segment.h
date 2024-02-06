


#ifndef SEGMENT_H_
#define SEGMENT_H_
void seven_seg_init(unsigned char port);
void seven_seg_write(unsigned char port,unsigned char number);
void seven_seg_bcd_init(unsigned char port);
void seven_seg_bcd_write_low(unsigned char port,unsigned char value);
void seven_seg_bcd_write_high(unsigned char port,unsigned char value);







#endif /* 7SEGMENT_H_ */