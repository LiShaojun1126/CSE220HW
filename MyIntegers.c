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
   if ((source_repr != 'S' && source_repr != '2') || (target_repr != 'S' && target_repr != '2')){
       printf("error\n");
       return;
   }

   //when the source repre is the same as target repr, we don't need to do anything
   if (source_repr == target_repr){
       if (target_repr == 'S' && repr == 0x80000000) { //special case
            printf("00000000\n"); // +0
        }
       printf("%08x\n", repr); //to ensure is 32bits
       return;
   }

   if (source_repr == 'S' && target_repr == '2'){
       if(repr == 0x80000000) { //handling -0
           printf("00000000\n"); return;
       }
       unsigned int s_sign = repr & sign_mask;
       //printf("current sign is: %x\n",s_sign);
       if(s_sign){ //negative
           unsigned int abs_repr = repr & 0x7FFFFFFF; //get abs value
           unsigned int result_to_two = ~(abs_repr) + 1;

           printf("%08x\n", result_to_two);
           return;
       }
        printf("%08x\n",repr);       //positive which is the same as two's complement
        return;
   }

   if (source_repr == '2' && target_repr == 'S'){
       unsigned int two_sign = repr & sign_mask;
       //printf("current sign is: %x\n", two_sign);
       if(two_sign){
           unsigned int result_to_S = ~(repr - 1);

           result_to_S |= two_sign;  //we need to add the sign back here

           printf("%08x\n", result_to_S);
           return;
       }
       printf("%08x\n", repr);//positive
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
