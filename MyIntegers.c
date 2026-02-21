#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>
//Shaojun Li 117646117
#define sign_mask 0x80000000
void repr_convert(char source_repr, char target_repr, unsigned int repr) {

   /*
    * TODO:
    * 1. Validate source_repr and target_repr
    * 2. Decode the source representation
    * 3. Convert to target representation
    * 4. Print the result or error message
    */
   //range of 32bit sign/magnitude : [-(2 ^ 31 - 1), (2 ^ 31) - 1]
   //range of 2's complement: [-2 ^ 31, 2 ^ 31 - 1]
   // therefore -2^31 cannot be represented in sign/magnitude
   if (source_repr == '2' && target_repr == 'S' &&repr == 0x80000000){ //0x80000000 = 1000 0000 0000 0000 0000 0000 0000 0000 = -2^31 in two's complement
       printf("undefined\n");
       return;
   }
   if (source_repr != 'S' && source_repr != '2' || target_repr != 'S' && target_repr != '2'){
       printf("error\n");
       return;
   }

   //when the source repre is the same as target repr, we don't need to do anything
   if (source_repr == target_repr){
       printf("%x\n", repr);
       return;
   }

   if (source_repr == 'S'){
       if(repr == 0x80000000) { //handling -0
           printf("0000000\n"); return;
       }
       int s_sign = repr & sign_mask;
       printf("current sign is: %x\n",s_sign);
       if(s_sign){ //negative
           repr &= 0x7FFFFFFF;
           repr ^= 0x7FFFFFFF;
           repr += 1;
           repr |= s_sign;

           printf("%x\n", repr);
           return;
       }
       //positive
        printf("%x\n",repr);
        return;
   }

   if (source_repr == '2'){
       int two_sign = repr & sign_mask;
       printf("current sign is: %x\n", two_sign);

       if(two_sign){
           repr --;
           repr ^= 0x7FFFFFFF; //invert
           repr |= two_sign;

           printf("%x\n", repr);
           return;
       }

       printf("%x\n", repr);
       return;
   }
}

//test, to delete:
// int main(){
//     repr_convert('S', '2', 0x80000001);
//     repr_convert('S', '2', 0x80000000);
//     repr_convert('2', '2', 0x59f2ca50);
//     repr_convert('F', '2', 0x00394812);
//     repr_convert('2', 'S', 0x80000000);
//     return 0;
// }
