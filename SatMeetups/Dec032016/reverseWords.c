/**
 * \file ReverseWords of a sentence inplace
 *
 */

#include <stdio.h>
#include <string.h>

void reverseWords(char* a) {
  size_t n;
  if (a == NULL || (n = strlen(a)) < 2) return;
  for (size_t i = 0; i < n/2; i++) {
    char tmp = a[i];
    a[i] = a[n-i-1];
    a[n-i-1] = tmp;
  }
  size_t i = 0, j = 0;
  while (a[i] != '\0') {
    while ((a[j] != ' ') && (a[j] != '\0')) {j++;}
    for (size_t k = i; k < (j+i)/2; k++) {
      char tmp = a[k];
      a[k] = a[i+j-k-1];
      a[i+j-k-1] = tmp;
    }
    if (a[j] == ' ') j++;
    i = j;
  }
  printf("%s\n", a);
}

void reverseWordR(char* a, size_t n) {
  if (a == NULL || n < 2) return;
  char tmp = a[0];
  a[0] = a[n-1];
  a[n-1] = tmp;
  reverseWordR(a+1, n-2);
}

void reverseWordsR(char* a) {
  size_t n;
  if (a == NULL || (n = strlen(a)) < 2) return;
  reverseWordR(a, n);
  size_t i = 0, j = 0;
  while (a[i] != '\0') {
    while (a[j] != ' ' && a[j] != '\0') j++;
    reverseWordR(a+i, j-i);
    if (a[j] == ' ') j++;
    i = j;
  }
  printf("%s\n", a);
}

int main() {
  char a[] = "a good day";
  reverseWords(a);
  char b[] = "todays meetup was quite interesting";
  reverseWords(b);
  reverseWordsR(a);
  reverseWordsR(b);

  return 0;
}
