#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > Permute(vector<int> i) {
  vector<vector<int> > result;
  if (i.size() == 1) {
    result.push_back(i);
    return result;
  }
  int x = i[0];
  //cout << x << endl;
  auto tmp = Permute(vector<int>(i.begin()+1, i.end()));
  //cout << tmp[0][0] << endl;
  for (int j = 0; j < tmp.size(); j++) {
    int sz = tmp[j].size();
    auto m = vector<int>(tmp[j]);
    for (int k = 0; k <= sz; k++) {
      tmp[j].insert(tmp[j].begin()+k, x);
      //cout << tmp[j][k] << endl;
      result.push_back(vector<int>(tmp[j]));
      tmp[j] = m;
    }
  }
  //cout << "blah" << endl;
  return result;
}


int main() {
  for (auto i : Permute({1, 2, 3, 4})) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
