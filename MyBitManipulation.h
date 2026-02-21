#ifndef MY_BIT_MANIPULATION_H
#define MY_BIT_MANIPULATION_H
#include <stdint.h>
//Name: Shaojun Li SBUID: 117646117
int ToggleBit(int num, int pos);
int GetMSB(int num);
int ClearBitRange(int num, int start, int end);
uint32_t RotateLeft(uint32_t num, int d);
int SwapOddEvenBits(int num);

#endif
