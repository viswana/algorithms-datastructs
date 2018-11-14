#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kmpsearch(const string& searchWord) {
  if (!searchWord.size()) return -1;
  
  //Generate partial match table
  vector<int> ptable;
  size_t i = 1, j = 0;
  ptable.push_back(0);
  ptable.push_back(0);
  for (; i < searchWord.size(); ++i) {
    if (searchWord[j] == searchWord[i]) {
      ptable.push_back(j+1);
      ++j;
    }
    else {
      ptable.push_back(0);
      j = 0;
    }
  }
  cout << "ptable" << endl;
  for (auto i : ptable)
    cout << i  << ", ";
  cout << endl;
  string line;
  int count = 0;
  while (getline(cin, line)) {
    size_t i = 0, j = 0;
    for (; i < line.size();) {
      if (line[i] == searchWord[j]) {
	++i;
	++j;
	if (j >= searchWord.size()) {
	  cout << i-j << endl;
	  count++;
	  j = ptable[j];
	}
      }
      else {
	j = ptable[j];
	if (!j) ++i;
      }
    }
  }
  return count;
}

int main() {
  cout << kmpsearch("aa") << endl;
  return 0;
}
