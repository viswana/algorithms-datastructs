#include <iostream>
#include <vector>
using namespace std;

void PowerSet(const vector<int>& input, int idx, vector<vector<int> >& out) {
  if (idx >= input.size()) {
    out.push_back(vector<int>{});
    return;
  }
  PowerSet(input, idx+1, out);
  //cout << out.size() << endl;
  vector<vector<int> > temp(out);
  for (auto i : temp) {
    i.push_back(input[idx]);
    out.push_back(i);
  }
}

int main() {
  vector<vector<int> > out;
  PowerSet({1, 2, 3, 5, 6}, 0, out);
  cout << out.size() << endl;
  for (auto i : out) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
