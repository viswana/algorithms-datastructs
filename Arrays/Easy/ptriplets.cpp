#include <iostream>
using namespace std;

//a^2+b^2 = c^2.
//For all positive integers n and m. n > m, 
//use equations, a = n^2-m^2, b = 2*m*n, c = n^2+m^2 as long as c < limit
//This is Euclid's method for generating pythagorean triplets. 

#define LIMIT 1000

int main() {
  int m = 1, n = 2, c = n*n + m*m;
  while (c <= LIMIT) {
    for (m = 1; m < n; m++) {
      int a = n*n - m*m, b = 2*m*n;
      c = n*n + m*m;
      if (c > LIMIT)
        break;
      if (a < b) cout << a << " " << b << " " << c << endl;
    }
    n++;
  }
}
