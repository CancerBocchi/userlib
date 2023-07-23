#ifndef __OLEDUI_H__
#define __OLEDUI_H__



#include "main.h"
#include "stdbool.h"

#define SCREEN_COLUMN 128
#define SCREEN_ROW 64
#define SCREEN_PAGE_NUM 8
#define NUM_OFCHINESE   8
#define MAX(x,y)  		((x)>(y)? (x):(y))
#define MIN(x,y)  		((x)<(y)? (x):(y))

#ifdef cplusplus
extern "C"{
#endif // cplusplus

typedef struct COORDINATE 
{
	int x;
	int y;
}Type;

typedef enum
{
	TEMPBUFF_COP_TO_SCREEN,
	TEMPBUFF_CLEAN,
	TEMPBUFF_COVER_L,
	TEMPBUFF_COVER_H
	
}Type_tempbuff;

struct Cn16CharTypeDef                	// 汉字字模数据结构 
{
	unsigned char  Index[2];            // 汉字内码索引,一个汉字占两个字节	
	unsigned char  Msk[32];             // 点阵码数据(16*16有32个数据) 
};

void OLED_CleanBuffer(void);
void flash(void);
unsigned char pgm_read_byte(const unsigned char *addr);
unsigned int oled_pow(unsigned char m,unsigned char n);
void SetPointBuffer(uint8_t , uint8_t ,uint8_t);
void DrawPiel(uint8_t , uint8_t ,uint8_t);
void DrawLine(uint8_t , uint8_t , uint8_t , uint8_t );
void DrawFastHLine(uint8_t , uint8_t , uint8_t );
void DrawFastVLine(uint8_t , uint8_t , uint8_t );
void DrawCircleHelper(uint8_t,uint8_t, unsigned char , unsigned char);
void DrawRoundRect(uint8_t , uint8_t , unsigned char w, unsigned char h, unsigned char r);
void DrawChar(uint8_t , uint8_t , unsigned char c,float size,uint8_t bg);
void DrawString(uint8_t,uint8_t,char *str,uint8_t);
void DrawNum(uint8_t, uint8_t,uint16_t,uint8_t,float,uint8_t);
void DrawHalfRoundRect(uint8_t x,uint8_t y,uint8_t w,uint8_t h,uint8_t direction);

void OLED_Screen(int Value,float Vout,float Iout,float PowerFactor,float V_Grid);
void OLED_DrawFloat(uint8_t,uint8_t ,float);

#ifdef cplusplus
}
#endif // cplusplus

#endif // !__OLED_H__