#include <iostream>
#include <string>
#include <vector>
using namespace std;

void TextEdit(const string& searchWord, const string& replaceWord) {
  string line;
  while (getline(cin, line)) {
    int i = 0, j = 0;
    while (i < (int)(line.size() - searchWord.size())) {
      if (searchWord[j] == line[i+j]) {
	++j;
	if (j >= searchWord.size()) {
	  for (size_t x = 0; x < replaceWord.size(); ++x) {
	    cout << replaceWord[x];
	  }
	  i += searchWord.size();
	  j = 0;
	}
      }
      else {
	cout << line[i];
	j = 0;
	++i;
      }
    }
    while (i < line.size()) {
      cout << line[i];
      ++i;
    }
    cout << endl;
  }
}

void TextEdit1(const string& searchWord, const string& replaceWord) {
  string line;
  while (getline(cin, line)) {
    int i = 0;
    for (; i < (int)(line.size() - searchWord.size());) {
      size_t j = 0;
      for (; j < searchWord.size() && searchWord[j] == line[i+j]; ++j);
      if (j >= searchWord.size()) {
	for (size_t k = 0; k < replaceWord.size(); ++k) cout << replaceWord[k];
	i += searchWord.size();
      }
      else {
	cout << line[i];
	++i;
      }
    }
    for (; i < line.size(); ++i) {
      cout << line[i];
    }
    cout << endl;
  }
}

void TextEdit2(const string& searchWord, const string& replaceWord) {
  if (!searchWord.size() || searchWord == replaceWord) return;
  string line;
  while(getline(cin, line)) {
    size_t i = 0, j = 0;
    for (; i < line.size();) {
      if (searchWord[j] == line[i]) {
	++i;
	++j;
	if (j >= searchWord.size()) {
	  for (size_t k = 0; k < replaceWord.size(); ++k) cout << replaceWord[k];
	  j = 0;
	}
      }
      else {
	cout << line[i-j];
	i = i-j+1;
	j = 0;
      }
    }
    cout << endl;
  }
}

void KmpTextEdit(const string& searchWord, const string& replaceWord) {
  if (!searchWord.size() || searchWord == replaceWord) return;
  //Generate partial match table
  vector<int> ptable = {0, 0}; //entires 0 and 1 are 0
  size_t i = 1, j = 0;
  for (; i < searchWord.size(); ++i) {
    if (searchWord[j] == searchWord[i]) {
      ++j;
    }
    else {
      j = 0;
    }
    ptable.push_back(j);
  }
  string line;
  while(getline(cin, line)) {
    size_t i = 0, j = 0;
    while (i < line.size()) {
      if (searchWord[j] == line[i]) {
	++i;
	++j;
	if (j >= searchWord.size()) {
	  for (size_t x = 0; x < replaceWord.size(); ++x)
	    cout << replaceWord[x];
	  j = 0;
	}
      }
      else {
	for (size_t x = i-j; x <= i; ++x)
	  cout << line[x];
	j = ptable[j];
	if (!j) ++i;
      }
    }
    cout << endl;
  }
}

int main() {
  KmpTextEdit("ece", "ese");
  return 0;
}
