#include <iostream>
#include <vector>
using namespace std;

//lmiss - Longest Montonically Increasing SubSequence
int lmiss (const vector<int>& in, vector<vector<int> >& out) {
  if (!in.size()) return -1;
  int maxlen = 1;
  size_t pmax = 0;
  vector<unsigned int> length(in.size(), 1);
  out.push_back({in[0]});
  for (size_t i = 1; i < in.size(); ++i) {
    int current = in[i];
    vector<int> currlmiss;
    if (current < in[pmax]) {
      unsigned int maxj = 1;
      for (size_t j = 0; j < i; ++j) {
	if (in[j] < current) {
	  if (!currlmiss.size() || in[j] > currlmiss[currlmiss.size()-1]) {
	    currlmiss.push_back(in[j]);
	  }
	  if (length[j] > maxj) {
	    maxj = length[j];
	  }
	}
      }
      length[i] = maxj + 1;
      currlmiss.push_back(in[i]);
      if (maxj + 1 > maxlen) {
	maxlen = maxj + 1;
	pmax = i;
      }
    }
    else {
      maxlen += 1;
      length[i] = maxlen;
      pmax = i;
      for (auto& y : out) {
	y.push_back(in[i]);
      }
    }
    if (currlmiss.size() > out[0].size()) {
      out.clear();
      out.push_back(currlmiss);
    }
    else if (currlmiss.size() == out[0].size()) {
      out.push_back(currlmiss);
    }
  }
  return maxlen;
}

int main() {
  vector<vector<int> > out;
  cout << lmiss({1, 2, 9, 4, 7, 3, 11, 8, 14, 6}, out) << endl;
  for (auto i : out) {
    for (auto j : i) {
      cout << j << ", ";
    }
    cout << endl;
  }
  return 0;
}
