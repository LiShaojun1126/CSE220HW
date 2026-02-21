#include "Myfloat.h"
#include <stdio.h>
//Name: Shaojun Li SBUID: 117646117
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
   unsigned char sign = (unsigned char)sign_bit;

   // if (exponent > 127 || exponent < -127) { this if statement cannot prevent invalid output.
   //    printf("Invalid exponent\n");
   //    return 0;
   // }
   unsigned char expo = (unsigned char)exponent; //char is signed, we need to convert it, but we must use unsigned char otherwise it will complement many 0
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

// int main(){
//     printf("%f", construct_float_sf(0x00, 0x81, 0x300000));
//     printf("%f", construct_float_sf(0x01, 0x81, 0x300000));
//     printf("%f", construct_float_sf(0x00, 0x7F, 0x200000));
//     printf("%f", construct_float_sf(0x01, 0x7F, 0x200000));
//     printf("%f", construct_float_sf(0x00, 0x76, 0x299B6F));
//     printf("%f\n", construct_float_sf(0x01, 0x76, 0x299B6F));
//     printf("%g\n", construct_float_sf(0x00, 0x89, 0xABCDEF)); //this will print 1374.435425 using %f
//     printf("%g\n", construct_float_sf(0x01, 0x89, 0xABCDEF)); //this will print -1374.435425 %f
//     printf("%f", construct_float_sf(0x00, 0x90, 0x7973C0));
//     printf("%f", construct_float_sf(0x01, 0x90, 0x7973C0));


//     return 0;
// }
