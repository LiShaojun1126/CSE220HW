HW3/
├── Makefile
├── HW3_main.c
├── MyBitManipulation.h
├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c
├── MyIntegers.h
├── MyIntegers.c
└── README.txt


1- write your name and SBU ID in each of the file.
Name: Shaojun Li SBUID: 117646117

------ToggleBit:
return num when the position is out of boundary(0,31)
Used mask to implement
test cases:
   cr_assert_eq(ToggleBit(9, 0), 8);
   cr_assert_eq(ToggleBit(9, 3), 1);
   cr_assert_eq(ToggleBit(9, 1), 11);
   cr_assert_eq(ToggleBit(0, 0), 1);
   cr_assert_eq(ToggleBit(0, 31), 0x80000000);
   cr_assert_eq(ToggleBit(-1, 31), 0x7FFFFFFF);
   cr_assert_eq(ToggleBit(-1, 0), -2);
   cr_assert_eq(ToggleBit(-1, 32), -1);
   cr_assert_eq(ToggleBit(-1, -3), -1);

result: all PASS

------GetMSB:
directly return 31 when num is less than 0

test cases:
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);
   cr_assert_eq(GetMSB(-1), 31);
   cr_assert_eq(GetMSB(-2), 31);
   cr_assert_eq(GetMSB(-3), 31);
   cr_assert_eq(GetMSB(0x7FFFFFFF), 30);
   cr_assert_eq(GetMSB(1), 0);
   cr_assert_eq(GetMSB(2), 1);
result: all PASS


------ClearBitRange:
using mask
handled the boundary situation: start < 0 or end > 31 or end < start

test cases:
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
result: All PASS


------RotateLeft:

Handle the situation that d is larger than 31 using %=
return num directly when d is 0 to prevent undefined behavior

test cases:
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);
   //below is the test I wrote
   cr_assert_eq(RotateLeft(0x12345678, 4), 0x23456781);
   cr_assert_eq(RotateLeft(0x12345678, 8), 0x34567812);

   cr_assert_eq(RotateLeft(0x80000000, 1), 1);
   cr_assert_eq(RotateLeft(1, 31), 0x80000000);
   cr_assert_eq(RotateLeft(567, 32), 567);
   cr_assert_eq(RotateLeft(567, 64), 567);

result: all PASS


------SwapOddEvenBits:
create 2 masks
convert the number into unsigned to avoid adding heading 1 when the num is negative,
then implicitly convert back when return.

test cases:
   cr_assert_eq(SwapOddEvenBits(23), 43);

   //below is the test I write
   cr_assert_eq(SwapOddEvenBits(0), 0);
   cr_assert_eq(SwapOddEvenBits(0xFFFFFFFF), 0xFFFFFFFF);
   cr_assert_eq(SwapOddEvenBits(0xAAAAAAAA), 0x55555555);
   cr_assert_eq(SwapOddEvenBits(0x55555555), 0xAAAAAAAA);
result: all PASS

------construct_float_sf:
in my code, I used a lot usigned char or unsigned int to prevent undefined behavior or stange things to happend
created mask
tested all examples in hw pdf
test cases:

Test(ConstructFloat, positive_examples) {
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   cr_assert_float_eq(f, 1.25, 0.00001);
}

Test(ConstructFloat, negative_examples) {
   float f = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f, -1.25, 0.00001);

}

//below is my test
Test(ConstructFloat, zero_example) {
    // sign=0, exp=0, frac=0
    float f = construct_float_sf(0x00, 0x00, 0x000000);
    cr_assert_float_eq(f, 0.0, 0.00001);
}
Test(ConstructFloat, one_example) {
    float f = construct_float_sf(0x00, 0x7F, 0x000000);
    cr_assert_float_eq(f, 1.0, 0.00001);
}

Test(ConstructFloat, negative_one_example) {
    float f = construct_float_sf(0x01, 0x7F, 0x000000);
    cr_assert_float_eq(f, -1.0, 0.00001);
}

Test(ConstructFloat, positive_examples) {
    float f = construct_float_sf(0x00, 0x7F, 0x400000);
    cr_assert_float_eq(f, 1.5, 0.00001);
}
Test(ConstructFloat, positive_examples) {
    float f = construct_float_sf(0x00, 0x80, 0x000000);
    cr_assert_float_eq(f, 2.0, 0.00001);
}

Test(ConstructFloat, positive_examples) {
    float f = construct_float_sf(0x00, 0x81, 0x300000);
    cr_assert_float_eq(f, 5.5, 0.00001);
}

Test(ConstructFloat, negative_examples) {
    float f = construct_float_sf(0x01, 0x81, 0x300000);
    cr_assert_float_eq(f, -5.5, 0.00001);
}

Test(ConstructFloat, positive_examples) {
    float f = construct_float_sf(0x00, 0x7F, 0x200000);
    cr_assert_float_eq(f, 1.25, 0.00001);
}

Test(ConstructFloat, negative_examples) {
    float f = construct_float_sf(0x01, 0x7F, 0x200000);
    cr_assert_float_eq(f, -1.25, 0.00001);
}

Test(ConstructFloat, pos_small_fraction) {
    float f = construct_float_sf(0x00, 0x76, 0x299B6F);
    cr_assert_float_eq(f, 0.002588, 0.000001);
}

Test(ConstructFloat, neg_small_fraction) {
    float f = construct_float_sf(0x01, 0x76, 0x299B6F);
    cr_assert_float_eq(f, -0.002588, 0.000001);
}

//this will lose a lot precision
Test(ConstructFloat, pos_lost_precision) {
    float f = construct_float_sf(0x00, 0x89, 0xABCDEF);
    cr_assert_float_eq(f, 1374.44, 0.01);
}

Test(ConstructFloat, neg_lost_precision) {
    float f = construct_float_sf(0x01, 0x89, 0xABCDEF);
    cr_assert_float_eq(f, -1374.44, 0.01);
}

Test(ConstructFloat, positive_examples9) {
    float f = construct_float_sf(0x00, 0x90, 0x7973C0);
    cr_assert_float_eq(f, 255439.0, 0.00001);
}

Test(ConstructFloat, negative_examples) {
    float f = construct_float_sf(0x01, 0x90, 0x7973C0);
    cr_assert_float_eq(f, -255439.0, 0.00001);
}

result: all PASS


------repr_convert:
I used printf to print out all results. That's why you will see some output text when you run the test file.

Handled with many wrong inputs
Able to print positive 0 when source_repr and target_repr are all 'S' and number is negative 0(0x80000000)
tested all examples in hw pdf
test cases:
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('S', '2', 0x80000000);
   repr_convert('S', '2', 0x80000001);
   repr_convert('F', '2', 0x00394812);
   repr_convert('2', 'S', 0x80000000);
   //below is the test I wrote
   //negative
   repr_convert('2', 'S', 0xFFFFFFFF); //Expected: 80000001

   repr_convert('2', 'S', 0xFFFFFFFB); //Expected: 80000005
   repr_convert('S', '2', 0x80000005);//Expected: fffffffb

   //0s
   repr_convert('S', '2', 0x00000000); //Expected: 00000000
   repr_convert('2', 'S', 0x00000000); //Expected: 00000000
   repr_convert('S', 'S', 0x00000000); //Expected: 00000000

   // max integer
   repr_convert('S', '2', 0x7FFFFFFF); //Expected: 7fffffff
   repr_convert('2', 'S', 0x7FFFFFFF); //Expected: 7fffffff

   //wrong input
   repr_convert('2', 'Q', 0x12345678); //Expected: error
   repr_convert('X', 'Y', 0x12345678); //Expected: error
results: all PASS


I have tested all the examples appear in the HW pdf file and added some my own test cases.
For detail comments, please view my source code of each part. I created many comments inside the source code.

I commented out the cases that I created, but keep those original test cases
