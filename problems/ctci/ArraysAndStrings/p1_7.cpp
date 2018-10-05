#include <iostream>
using namespace std;

const int n = 5;
void rotateMatrix(char a[][n], bool clockwise) {
  for (int l = 0; l < n/2; l++) {
    for (int i = l, j = n-1-l; i < n-1-l && j > l; ++i, --j) {
      char tmp1 = a[l][i];
      char tmp2 = a[j][l];
      char tmp3 = a[n-1-l][j];
      char tmp4 = a[i][n-1-l];
      if (clockwise) {
	a[j][l] = tmp3;
	a[n-1-l][j] = tmp4;
	a[i][n-1-l] = tmp1;
	a[l][i] = tmp2;
      }
      else {
	a[j][l] = tmp1;
	a[n-1-l][j] = tmp2;
	a[i][n-1-l] = tmp3;
	a[l][i] = tmp4;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  
  char a[][5] = { {'a', 'b', 'c', 'd', 'e'},
		  {'f', 'g', 'h', 'i', 'j'},
		  {'k', 'l', 'm', 'n', 'o'},
		  {'p', 'q', 'r', 's', 't'},
		  {'u', 'v', 'w', 'x', 'y'}
  };
  
  //char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
  //	      'm', 'n', 'o', 'p'};
  //char a[] = {'a','b', 'c', 'd'};
  //char* b[4];
  //for (int i = 0; i < 4; i++)
  //  b[i] = a[i];
  rotateMatrix(a, true);
  /*
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << *(char*)(a+i*4+j) << " ";
    }
    cout << endl;
  }
  */
  return 0;
}
