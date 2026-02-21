// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdint.h>
#include <stdio.h>
//Name: Shaojun Li SBUID: 117646117
/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   /* TODO: implement */
   // to avoid expections
   if (pos < 0 || pos > 31){
       //printf("Your position %d is invalid, the number stays the same, please re-enter!\n", pos);
       return num;
   }
   //we need a mask here
   uint32_t mask_ToggleBit = 1U << pos; //create and shift the mask，using unsighed mask to avoid undefined behavior
   num ^= mask_ToggleBit; //toggle the bit using XOR, any bit xor 1 will flip it
   return num;
}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   /* TODO: implement */
   if (num == 0){
       return -1;
   }

   if (num < 0) return 31; //bit 31 is always 1 for negative number

   uint32_t result = 0; //result will not be a negative number
   while (num > 1){ //while num > 1, we haven't reach most significant 1
       num >>= 1;
       result ++;
   }
   return result; //result is the index of the position, while result is the nth postion(starts with 1)
}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) { //also use XOR， XOR itself
   /* TODO: implement */
   if(start < 0 || end > 31 || end < start) {
       //printf("The start or the end is invalid, please re-enter.\n");
       return num;
   }

   //creating mask
   uint32_t num_of_ones = end - start + 1;
   uint32_t mask_ClearBitRange = 1;

   while(--num_of_ones){ //create mask like 0000 1111 0000
           mask_ClearBitRange <<= 1;
           mask_ClearBitRange ++;
   }
   //shift the mask
   uint32_t gap_between_0_and_start  = start;
   while(gap_between_0_and_start --){
       mask_ClearBitRange <<= 1;
   }
   // to get the correct mask as the same as part of num, use &
   mask_ClearBitRange &= num;

   return num ^= mask_ClearBitRange;
}

/*
* Rotate num to the left by d bits
*/
uint32_t RotateLeft(uint32_t num, int d) {
   /* TODO: implement */
   if (d >= 32) d %= 32; //for example, rotate 35bits = rotate 3 bits
   // uint32_t leftside = num << d;
   // uint32_t rightside = num >> (32 - d);

   //to prevent undefined behavior:
   if (d == 0) return num;

   return num << d | num >> (32 - d);
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   /* TODO: implement */
   //convert to unsigned:
   uint32_t u_num = (uint32_t)num;
   //create mask:
   uint32_t mask_even_bits = 0xAAAAAAAA;
   uint32_t mask_odd_bits = 0x55555555;

   uint32_t even_bits = num & mask_even_bits, odd_bits = num & mask_odd_bits;
   even_bits >>= 1;
   odd_bits <<= 1;

   //implicitly convert back
   return even_bits | odd_bits;
}

// //To Delete finally:

// int main(){
//     printf("%d\n", ToggleBit(-1, 31));
//     printf("%d\n",ClearBitRange(73,1,3));
//     printf("%u\n", RotateLeft(2147483647, 1));
//     printf("%d", SwapOddEvenBits(-4));
//     return 0;
// }
