#include <iostream>
#include <string>
using namespace std;

#define isAlpha(x) (\
		    ((x - 'a') >= 0 && (x - 'a') < 26) ||\
		    ((x - 'A') >= 0 && (x - 'A') < 26))

int WordSearch(const string& searchWord) {
  if (!searchWord.size()) return -1;
  int nwords = 0;
  char pre = ' ';
  char post;
  size_t i = 0;
  char c;
  while (cin.get(c)) {
    if (c == searchWord[i]) {
      ++i;
      if (i == searchWord.size()) {
	if(cin.get(post)) {
	  if (!isAlpha(pre) && !isAlpha(post)) ++nwords;
	  i = 0;
	  pre = post;
	}
	else {
	  return nwords;
	}
      }
    }
    else {
      pre = c;
      i = 0;
    }
  }
  return nwords;
}

int WordSearch2(const string& searchWord) {
  if (!searchWord.size()) return -1;
  int nwords = 0;
  char pre = ' ';
  char post;
  size_t i = 0;
  string line;
  while (getline(cin, line)) {
    bool lineprinted = false;
    for (size_t j = 0; j < line.size();) {
      if (searchWord[i] == line[j]) {
	++i;
	++j;
	if (i == searchWord.size()) {
	  if (j >= line.size()) post = ' ';
	  else {
	    post = line[j];
	  }
	  if (!isAlpha(pre) && !isAlpha(post)) {
	    nwords++;
	    if (!lineprinted) cout << line << endl;
	    lineprinted = true;
	  }
	  i = 0;
	  pre = post;
	}
      }
      else {
	pre = line[j];
	i = 0;
	++j;
      }
    }
  }
  return nwords;
}

int main() {
  cout << WordSearch("mail") << endl;
  return 0;
}
