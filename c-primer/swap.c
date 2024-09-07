// Copyright (c) 2024 MIT License by 6.106 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void swap(int * const i, int * const j) {
  const int temp = *i;
  *i = *j;
  *j = temp;
}

int main() {
  int k = 1;
  int m = 2;
  swap(&k, &m);
  // What does this print?
  printf("k = %d, m = %d\n", k, m);

  return 0;
}
