// Copyright (c) 2024 MIT License by 6.106 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {  // What is the type of argv?
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.106";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print?

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid?

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2? #mraz: pointer to a const char aka the char's not allowed to change, the pointer is!

  // For each of the following, why is the assignment:
  //*pcc = '7';  // invalid? //#mraz: not allowed to change the char!
  pcc = *pcp;  // valid?
  pcc = argv[0];  // valid?

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  //cp = *pcp;  // invalid?  //#mraz: nope, changing the pointer!
  //cp = *argv;  // invalid? //#mraz: nope, you're changing the pointer. Bzzzt!
  *cp = '!';  // valid? // #mraz: yes, the pointer remained constant, but the pointee is allowed to mutate

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  //cpc = *pcp;  // invalid? //#mraz: not allowed to mutate the pointer!
  //cpc = argv[0];  // invalid? //#mraz:: no allowed to mutate the pointer!
  //*cpc = '@';  // invalid? //#mraz: not allowed to mutate the pointee!

  return 0;
}
