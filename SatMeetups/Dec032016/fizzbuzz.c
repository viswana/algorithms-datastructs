/**
 * Print numbers between 1 to 100 inclusive, except
 * print Fizz for every mulitple of 3, Buzz for
 * every multiple of 5 and FizzBuzz for every multiple of
 * 3 and 5
 */

#include <stdio.h>

void fizzbuzz() {
  for (size_t i = 1; i <= 100; i++) {
    if (i % 3 == 0 && i % 5 == 0) printf("FizzBuzz\n");
    else if (i % 3 == 0) printf("Fizz\n");
    else if (i % 5 == 0) printf("Buzz\n");
    else printf("%lu\n", i);
  }
}
int main() {
  fizzbuzz();
  return 0;
}
