#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isPrime(size_t n) {
  if (n < 2) return false;
  if (!(n & 1)) return false;
  for(size_t i = 3; i*i < n; i += 2) {
    if (!(n % i)) return false;
  } 
  return true;
}

//Binary search to find integer square root
size_t floorSqrt(size_t n) {
  if (n < 2) return n;
  //Enough to check till n/2 as floor square root cannot be greater than n/2 for n>1
  size_t lo = 1, hi = n/2, mid = (hi+lo)/2, tmp;
  while (lo <= hi) {
    tmp = mid*mid;
    if (tmp == n) break;
    if (tmp > n) hi = mid-1;
    else lo = mid+1;
    mid = (hi+lo)/2;
  }
  return mid;
}

void findPrimes(size_t n, set<size_t>& cache) {
  if (n < 2) return;
  //vector<bool> primeVec(n, false);
  bool isCacheEmpty = cache.empty();
  size_t tsize;
  size_t maxprime;
  if (isCacheEmpty) {
    tsize = n+1;
  }
  else {
    maxprime = *cache.rbegin();
    size_t x = floorSqrt(maxprime);
    if (x*x < maxprime) x += 1;
    if (floorSqrt(n) <= x) return;
    tsize = n-maxprime;
  }
  size_t t[tsize];
  if (isCacheEmpty) {
    for (size_t i = 2; i < tsize ; i++)
      t[i] = i;
  }
  else {
    for(size_t i = 0, j = maxprime+1; i < tsize; i++, j++) {
      t[i] = j;
    }
  }
  //Find the minimum idx starting a 2 that is false;
  if (isCacheEmpty) {
    size_t minPrime = 1;
    size_t sqrtn = floorSqrt(n);
    while (minPrime <= sqrtn) {
      for (minPrime++; minPrime < n; minPrime++) 
        if (t[minPrime] != 0) break;
      for (size_t i = minPrime+minPrime; i < n; i += minPrime) {
        t[i] = 0;
      }
    }
    for(size_t i = 2; i < n; i++)
      if (t[i] != 0) cache.insert(i);
    return; 
  }
  else {
    //cout << "Checking for more primes" << endl;
    auto it = cache.begin();
    size_t minPrime = *it;
    size_t sqrtn = floorSqrt(n);
    for (; it != cache.end() && minPrime <= sqrtn; ++it, minPrime = *it) {
      for (size_t i = 0; i < tsize; i++) {
        if (t[i] > 0 && (t[i] % minPrime == 0)) t[i] = 0;
      }
    }
    if (it == cache.end()) {
      //cout << "Reached end of cache"<< endl;
      size_t i;
      for (i = 0; i < tsize; i++) {
        if (t[i] > 0) {
          minPrime = t[i]; 
          break;
        }
      }
      size_t nextpidx = i;
      while(minPrime <= sqrtn) {
        size_t nextprime;
        bool found = false;
        for (size_t j = nextpidx+1; j < tsize; j++) {
          if (t[j] > 0 && (t[j] % minPrime == 0)) t[j] = 0;
          else if (t[j] % minPrime) {
            if (!found) {
              nextprime = t[j];
              nextpidx = j;
              found = true;
            }
          }
        }
        minPrime = nextprime;
      }
    }
    for(size_t i = 0; i < tsize; i++)
      if (t[i] > 0) cache.insert(t[i]);
    return;
  }
}

bool isPrime2(size_t n, set<size_t>& cache) {
  if (n < 2) return false;
  findPrimes(n, cache);
  if (cache.count(n)) return true;
  return false;
}

int main() {
  set<size_t> primeCache;
  cout << isPrime(10) << endl;
  cout << isPrime2(10, primeCache) << endl;
  //for (auto i : primeCache) 
  //  cout << i << ", ";
  //cout << endl;
  cout << isPrime2(99907, primeCache) << endl;
  //for (auto i : primeCache) 
  //  cout << i << ", ";
  //cout << endl;
  cout << isPrime(99907) << endl;
}


