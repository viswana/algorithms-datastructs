#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dedup(vector<int>& a) {
  if (a.size() < 2) return a.size();
  int j = 1;
  for (int i = 0; i < a.size()-1; i++, j++) {
    if (a[i] == a[i+1]) {
      break;
    }
  }

  for (int i = j; i < a.size() - 1; i++) {
    if (a[i] != a[i+1]) {
      a[j] = a[i+1];
      j++;
    }
  }
  return j;
}

vector<string> permute(const string& i) {
  vector<string> out;
  if (i.size() == 1) {
    out.push_back(i);
    return out;
  }
  for (int j = 0; j < i.size(); j++) {
    string x(i);
    vector<string> tmp = permute(x.erase(j, 1));
    for (int k = 0; k  < tmp.size(); k++) {
      out.push_back(i[j] + tmp[k]);
    }
    //for(string s : permute(x.erase(j, 1))) {
    //  cout << s << endl;
    //  out.push_back(s.append(1,i[j]));
    //}
  }
  return out;
}

int main() {
  vector<int> a = {2, 3, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 9, 10};
  int x = dedup(a);
  for (int i = 0; i < x; i++)
    cout << a[i] << " ";
  cout << endl;
  for (auto x : permute ("abc")) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
  
}
