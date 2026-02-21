#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

/* =========================
* PART 1: Bit Manipulation
* ========================= */

Test(ToggleBit, examples) {
   cr_assert_eq(ToggleBit(9, 0), 8);
   cr_assert_eq(ToggleBit(9, 3), 1);

   //below is the test I wrote
   cr_assert_eq(ToggleBit(9, 1), 11);
   //boundary
   cr_assert_eq(ToggleBit(0, 0), 1);
   cr_assert_eq(ToggleBit(0, 31), 0x80000000);
   cr_assert_eq(ToggleBit(-1, 31), 0x7FFFFFFF);
   cr_assert_eq(ToggleBit(-1, 0), -2);

}

Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);

   //below is the test I wrote
   //negative
   cr_assert_eq(GetMSB(-1), 31);
   cr_assert_eq(GetMSB(-2), 31);
   cr_assert_eq(GetMSB(-3), 31);
   cr_assert_eq(GetMSB(0x7FFFFFFF), 30);
   cr_assert_eq(GetMSB(1), 0);
   cr_assert_eq(GetMSB(2), 1);
}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);

   //below is the test I wrote
   cr_assert_eq(ClearBitRange(73, 3, 1), 73);

   //out of boundary
   cr_assert_eq(ClearBitRange(73, -1, 3), 73);
   cr_assert_eq(ClearBitRange(73, -1, 32), 73);
   cr_assert_eq(ClearBitRange(73, 1, 32), 73);
   cr_assert_eq(ClearBitRange(73, 1, 33), 73);

   cr_assert_eq(ClearBitRange(0, 0, 31), 0);
   cr_assert_eq(ClearBitRange(0xFFFFFFFF, 0, 31), 0);
   cr_assert_eq(ClearBitRange(0xFFFFFFFF, 28, 31), 0x0FFFFFFF);
   cr_assert_eq(ClearBitRange(0xFFFFFFFF, 4, 7), 0xFFFFFF0F);
   cr_assert_eq(ClearBitRange(0xFFFFFFFF, 0, 0), 0xFFFFFFFE);

   cr_assert_eq(ClearBitRange(1, 0, 0), 0);

}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);
   //below is the test I wrote
   cr_assert_eq(RotateLeft(0x12345678, 4), 0x23456781);
   cr_assert_eq(RotateLeft(0x12345678, 8), 0x34567812);

   cr_assert_eq(RotateLeft(0x80000000, 1), 1);
   cr_assert_eq(RotateLeft(1, 31), 0x80000000);
   cr_assert_eq(RotateLeft(567, 32), 567);
   cr_assert_eq(RotateLeft(567, 64), 567);
}

Test(SwapOddEvenBits, examples) {
   cr_assert_eq(SwapOddEvenBits(23), 43);

   //below is the test I write
   cr_assert_eq(SwapOddEvenBits(0), 0);
   cr_assert_eq(SwapOddEvenBits(0xFFFFFFFF), 0xFFFFFFFF);
   cr_assert_eq(SwapOddEvenBits(0xAAAAAAAA), 0x55555555);
   cr_assert_eq(SwapOddEvenBits(0x55555555), 0xAAAAAAAA);

}

/* =========================
* PART 2: IEEE 754 Float
* ========================= */

Test(ConstructFloat, positive_examples) {
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   cr_assert_float_eq(f, 1.25, 0.00001);
}

Test(ConstructFloat, negative_examples) {
   float f = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f, -1.25, 0.00001);
}

/* =========================
* PART 3: Integer Conversion
* ========================= */
/* NOTE:
* We do NOT test output matching here.
* Students are encouraged to visually inspect output.
* TAs will use stronger hidden tests.
*/

Test(ReprConvert, basic_run) {
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('S', '2', 0x80000000);
   repr_convert('S', '2', 0x80000001);
   repr_convert('F', '2', 0x00394812);
   repr_convert('2', 'S', 0x80000000);
}
