#include <iostream>
using namespace std;

template <typename T>
T** alloc2D(int row, int col) {
  if (row < 1 || col < 1) return NULL;
  T** a = (T**) malloc(sizeof(T*)*row);
  if (a != NULL) {
    for (int i = 0; i < row; i++) {
      a[i] = (T*) malloc(sizeof(T)*col);
    }
  }
  return a;
}

int main() {
  int** x = alloc2D<int>(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      x[i][j] = i*j;
      cout << x[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < 3; i++) {
    free(x[i]);
  }
  free(x);
  return 0;
}
