#include <iostream>
#include <vector>
using namespace std;

vector<int> nextpermutation(vector<int> i) {
  vector<int> result;
  int j = i.size()-1;
  for (; j > 0 && i[j-1] >= i[j]; --j);
  if (!j) return result;
  int k = j;
  for (; k < i.size() && i[k] > i[j-1]; ++k);
  int temp = i[k-1];
  i[k-1] = i[j-1];
  i[j-1] = temp;
  for (int l = j; l <= (j + (i.size()-1-j)/2); l++) {
    int temp = i[l];
    i[l] = i[i.size()-1-l+j];
    i[i.size()-1-l+j] = temp;
  }
  return i;
}

int main() {
  for (auto i : nextpermutation({6,5,1,2,9,8,4,3})) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
