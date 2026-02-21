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


ToggleBit:
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

result: all PASS
GetMSB:
