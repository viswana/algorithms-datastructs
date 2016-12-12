#include <string.h>
#include <stdio.h>

void inplaceRLE(char* a, size_t n) {
  if (a == NULL || n < 3) return;
  char tmp = *a; 
  size_t count = 1;
  size_t i = 0, j = 1;
  while (a[j] != '\0') {
    if (a[j] != tmp) {
      if (count < 3) {
        while (count) {
          a[i] = tmp;
          i++;
          count--;
        }
      }
      else {
        char b[20];
        int cnt = 0;
        while (count > 0) {
          int x = count % 10;
          b[cnt] = '0' + x;
          cnt++;
          count  = count/10;
        }
        b[cnt] = '\0';
        while (cnt) {
          a[i] = b[cnt-1];
          i++;
          cnt--;
        }
        a[i] = tmp;
        i++;
      }
    }
    if (a[j] != '\0') tmp = a[j];
    j++;
    count++;
  }
  if (count < 3) {
    while (count) {
      a[i] = tmp;
      i++;
      count--;
    }
  }
  else {
    char b[20];
    int cnt = 0;
    while (count > 0) {
      int x = count % 10;
      b[cnt] = '0' + x;
      cnt++;
      count  = count/10;
    }
    b[cnt] = '\0';
    while (cnt) {
      a[i] = b[cnt-1];
      i++;
      cnt--;
    }
    a[i] = tmp;
    i++;
  }
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
