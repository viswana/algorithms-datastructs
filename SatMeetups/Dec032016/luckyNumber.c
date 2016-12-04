/**
 * \file Given a non negative integer, add the digits to reduce it to a single digit 
 */

#include <stdio.h>

void luckyNumber(unsigned long long n) {
  if (n < 10) printf ("%llu\n", n);
  unsigned long long sum = 0;
  while (n > 0) {
    unsigned int r = n % 10;
    sum += r;
    n /= 10; 
    if (n == 0 && sum > 9) {
      n = sum;
      sum = 0;
    }
  }
  printf ("%llu\n", sum);
}

unsigned long long luckyNumberR(unsigned long long n) {
  if (n < 10) return n;
  unsigned int r = n % 10;
  unsigned long long sum = 0;
  sum += r + luckyNumberR(n/10);
  if (sum > 9) return luckyNumberR(sum);
  return sum;
}

int main() {
  luckyNumber(5923);
  printf("%llu\n", luckyNumberR(5923));
  return  0;
}
