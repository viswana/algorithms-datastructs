#include <string.h>
#include <stdio.h>

#define FLUSH(ct, x)        \
  do {                      \
    if (ct < 3) {           \
      while (ct) {          \
        a[x] = tmp;         \
        x++;                \
        ct--;               \
      }                     \
    }                       \
    else {                  \
      char b[20];           \
      int cnt = 0;          \
      while (ct > 0) {      \
        int m = ct % 10;    \
        b[cnt] = '0' + m;   \
        cnt++;              \
        ct  = ct/10;        \
      }                     \
      b[cnt] = '\0';        \
      while (cnt) {         \
        a[x] = b[cnt-1];    \
        x++;                \
        cnt--;              \
      }                     \
      a[x] = tmp;           \
      x++;                  \
    }                       \
  } while(0)

void inplaceRLE(char* a, size_t n) {
  if (a == NULL || n < 3) return;
  char tmp = *a; 
  size_t count = 1;
  size_t i = 0, j = 1;
  while (a[j] != '\0') {
    if (a[j] != tmp) {
      FLUSH(count, i);
    }
    if (a[j] != '\0') tmp = a[j];
    j++;
    count++;
  }
  FLUSH(count, i);
  a[i] = '\0';
}

int main() {
  char a[]= "aaaabbaaaaaccccaaac";
  //char a[]= "aaaab";
  size_t len = strlen(a);
  inplaceRLE(a, len);
  printf("%s\n", a);
  return 0;
}
