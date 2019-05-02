#ifndef MAX7219_H
#define MAX7219_H

#define uchar unsigned char
#define uint  unsigned int

void Write_Max7219_char(uchar DATA);
void Write_Max7219(uchar address,uchar dat);
void Init_MAX7219(void);


#endif
