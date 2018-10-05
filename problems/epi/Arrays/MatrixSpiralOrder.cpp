#include <iostream>
#include <vector>
using namespace std;

void MatrixSpiralOrder(const vector<vector<int> >& m) {
  size_t rows = m.size();
  size_t cols = m[0].size();
  //if (rows == 1 && cols == 1) {
  //  cout << m[0][0] << endl;
  // return;
  //}
  int topb = 0;
  int botb = rows-1;
  int leftb = 0;
  int rightb = cols-1;
  int i = 0;
  int j = 0;
  while ((topb <= botb) && (leftb <= rightb)) {
    cout << m[i][j] << " ";
    if (i == topb && j < rightb) j++;
    else if (j == rightb && i < botb) i++;
    else if (i == botb && j > leftb) j--;
    else if (j == leftb  && i > topb) i--;
    if (i == topb && j == leftb) {
      botb--;
    }
    else if (i == botb && j == rightb) {
      topb++;
    }
    else if (i == botb && j == leftb) {
      rightb--;
    }
    else if (topb > 0 && i == topb && j == rightb) {
      leftb++;
    }
  }
  cout << m[i][j] << endl;
}

int main() {
  vector<vector<int> > m = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15}};
  vector<vector<int> > n = {{1}};
  MatrixSpiralOrder(m);
  return 0;
}
