/**
 * Copyright (c) 2024 MIT License by 6.106 Staff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/


/**
 * testbed.c:
 *
 * This file runs your code, tests it, and prints out the result.
 **/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "./is_power_of_two.h"


int main(int argc, char** argv) {
  int tests[] = {2, 3, 5, 16, (1 << 20), (1 << 21) - 5, (1 << 30), (1 << 30) + 1};
  bool expected[] = {true, false, false, true, true, false, true, false};
  int num_of_tests = sizeof(tests) / sizeof(int);

  for (int i = 0; i < num_of_tests; ++i) {
    int number_to_test = tests[i];
    int expected_is_power_of_2 = expected[i];
    bool result_is_power_of_2 = is_power_of_two(number_to_test);
    printf("%s! %d is%s a power of 2\n",
      (expected_is_power_of_2 == result_is_power_of_2) ? "Correct" : "Incorrect",
      number_to_test, expected_is_power_of_2 ? "" : " not");
  }

  int multiplication_of_powers_of_2 = 1;
  for (int i = 0; i < num_of_tests; ++i) {
    if (is_power_of_two(tests[i])) {
      multiplication_of_powers_of_2 *= tests[i];
    }
  }

  printf("Multiplication of all powers of 2 is: %d, make sure it is equal to 36028797018963968\n",
    multiplication_of_powers_of_2);

  return 0;
}
