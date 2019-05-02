#include "Arduino.h"

#define uchar unsigned char

static uchar Max7219_pinDIN = 8;
static uchar Max7219_pinCS   = 9;
static uchar Max7219_pinCLK = 10;

const char DECODEMODE = 0x09;
const char INTENSITY = 0x0a;
const char SCANLIMIT = 0x0b;
const char SHUTDOWN = 0x0c;
const char DISPLAYTEST = 0x0f;
//--------------------------------------------
//功能：向MAX7219(U3)写入字节
//入口参数：DATA
//出口参数：无
//说明：
void Write_Max7219_char(uchar DATA)
{
  uchar i;
  for (i = 8; i >= 1; i--)
  {
    digitalWrite(Max7219_pinCLK,LOW);
    digitalWrite(Max7219_pinDIN,DATA & 0x80);
    DATA = DATA << 1;
    digitalWrite(Max7219_pinCLK,HIGH);
  }
}
//-------------------------------------------
//功能：向MAX7219写入数据
//入口参数：address、dat
//出口参数：无
//说明：
void Write_Max7219(uchar address, uchar dat)
{
  digitalWrite(Max7219_pinCS, LOW);
  Write_Max7219_char(address);           //写入地址，即数码管编号
  Write_Max7219_char(dat);               //写入数据，即数码管显示数字
  digitalWrite(Max7219_pinCS, HIGH);
}

void Init_MAX7219(void)
{
  pinMode(Max7219_pinDIN, OUTPUT);
  pinMode(Max7219_pinCS, OUTPUT);
  pinMode(Max7219_pinCLK, OUTPUT);
  Write_Max7219(DECODEMODE, 0x00);       //译码方式：不译码
  Write_Max7219(INTENSITY, 0x03);       //亮度
  Write_Max7219(SCANLIMIT, 0x07);       //扫描界限；8个数码管显示
  Write_Max7219(SHUTDOWN, 0x01);       //掉电模式：0，普通模式：1
  Write_Max7219(DISPLAYTEST, 0x00);       //显示测试：1；测试结束，正常显示：0
}
