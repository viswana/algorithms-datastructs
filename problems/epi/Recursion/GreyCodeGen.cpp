#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> GreyCodeGen(int k) {
  if (!k) return vector<int>{0};

  vector<int> greycode_n_minus_1 = GreyCodeGen(k-1);

  vector<int> temp;
  for (int i = 0; i < greycode_n_minus_1.size(); i++) {
    temp.push_back((greycode_n_minus_1[i] << 1));
  }
  for (int i = greycode_n_minus_1.size()-1; i >= 0; --i) {
    temp.push_back((greycode_n_minus_1[i] << 1)|1);
  }
  return temp;
}

int main() {
  for (auto i : GreyCodeGen(4)) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
