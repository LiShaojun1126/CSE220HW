#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   /*
    * Start coding here
    * Use bitwise operations to construct the IEEE 754 float
    */
   if (sign_bit != 0 && sign_bit != 1) {
      printf("Invalid sign bit\n");
      return 0;
   }
   unsigned char sign = sign_bit;

   // if (exponent > 127 || exponent < -127) { this if statement cannot prevent invalid output.
   //    printf("Invalid exponent\n");
   //    return 0;
   // }
   unsigned char expo = exponent; //char is signed, we need to convert it, but we must use unsigned char otherwise it will complement many 0
   // printf("%u\n",expo);

   // int mantissa = fraction | (1 << 23); you should not care about the invisible 1
   // 0000 0000 0011 0000 0000 0000 0000 0000
   // 0000 0000 0111 1111 1111 1111 1111 1111 mask 0x007FFFFF
   unsigned int mask_fraction = 0x7FFFFF;
   unsigned int valid_frac = fraction & mask_fraction;

   f = sign << 31 | expo << 23 | valid_frac;
   // printf("%u\n", sign);
   // printf("%u\n", expo);
   // printf("%u\n", valid_frac);
   // printf("%u\n", f);

   return *(float *)&f;
}

int main(){
    printf("%f", construct_float_sf(0x00, 0x7F, 0x200000));

    return 0;
}
