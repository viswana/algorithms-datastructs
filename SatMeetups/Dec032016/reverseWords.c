/**
 * \file ReverseWords of a sentence inplace
 *
 */

#include <stdio.h>
#include <string.h>

void reverseWords(char* a) {
  if (a == NULL || strlen(a) < 2) return;
  size_t n = strlen(a);
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

int main() {
  char a[] = "a good day";
  reverseWords(a);
  char b[] = "todays meetup was quite interesting";
  reverseWords(b);
  return 0;
}
