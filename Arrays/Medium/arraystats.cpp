#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <algorithm>

using namespace std;
//-1 : Bad argument(s)
//0 : Search hit and if rank != NULL has the index
//1 : Search miss and if rank != NULL has potential index
int bSearch(int* a, size_t size, int key, size_t* rank) {
  int ret = -1;
  if (a == NULL || size == 0) return ret;
  size_t lo = 0, hi = size-1;
  while (lo <= hi) {
    size_t mid = (hi+lo)/2;
    if (a[mid] == key) {
      if (rank != NULL) *rank = mid;
      ret = 0; 
      break;
    }
    else if (key > a[mid]) {
      if (mid == hi) {
        if (rank != NULL) {
          if (mid < SIZE_MAX) *rank = mid+1;
          else *rank = mid;
        }
        ret = 1;
        break;
      }
      lo = mid+1;
    }
    else {
      if (mid == lo) {
        if (rank != NULL) {
          if (mid > 0) *rank = mid-1;
          else *rank = mid;
        }
        ret = 1;
        break;
      }
      hi = mid-1;
    }
  }
  return ret;
}

//This has O(n+m) n and m being the sizes of the arrays.
int commonItem(int* a, int* b, size_t asize, size_t bsize, int* soln) {
  int ret = -1;
  if (a == NULL || b == NULL || asize < 1 || bsize < 1) return ret;
  if (a[asize-1] >= b[0] && b[bsize-1] >= a[0]) {
    size_t i = 0, j = 0;
    while (i < asize && j < bsize) {
      if (a[i] == b[j]) {
        if (soln != NULL) *soln = a[i];
          ret = 0;
        break;
      }
      else if (a[i] < b[j]) i++;
      else j++;
    }
  }
  return ret;
}

//Complexity time, O(n), space O(n)
int firstRepeatingHashSet(int* a, size_t asize, int* soln) {
  int ret = -1;
  if (a == NULL || asize == 0) return ret;
  ret = 1;
  unordered_set<int> aset;
  for (size_t i = 0; i < asize; i++) {
    if (aset.count(a[i])) {
      ret = 0;
      if (soln != NULL) *soln = a[i];
      return ret;
    }
    else {
      aset.insert(a[i]);
    }
  }
  ret = 1;
  return ret;
}

//Complexity dominated by sort, O(nlogn), space O(1)
int firstRepeatingSort(int* a, size_t asize, int* soln) {
  int ret = -1;
  if (a == NULL || asize == 0) return ret;
  ret = 1;
  sort(a, a+asize);
  int tmp = a[0];
  for (size_t i = 1; i < asize; i++) {
    if (tmp == a[i]) {
      ret = 0;
      if (soln != NULL) *soln = tmp;
      return ret;
    }
    else {
      tmp = a[i]; 
    }
  }
  ret = 1;
  return ret;
}

//Complexity is O(n^2), space O(1)
int firstRepeatingBF(int* a, size_t asize, int* soln) {
  int ret = -1;
  if (a == NULL || asize == 0) return ret;
  ret = 1;
  for (size_t i = 0; i < asize-1; i++) {
    for (size_t j = i+1; j < asize; j++) {
      if (a[i] == a[j]) {
        ret = 0;
        if (soln != NULL) *soln = a[i];
        return ret;
      }
    }
  }
  ret = 1;
  return ret;
}

//O(n) time and O(1) extra space
int alternateIncDec(int* a, size_t asize) {
  if (a == NULL || asize < 3) return -1; 
  for (size_t i = 1; i < asize-1; i += 2) {
    int tmp = a[i];
    a[i] = a[i+1];
    a[i+1] = tmp;
  }
  return 0;
}

//O(n) time and O(1) space
int sumPosNeg(int* a, size_t asize, size_t* solnp, size_t* solnn) {
  if ( a == NULL || asize < 1 || solnp == NULL || solnn == NULL) return -1;
  size_t negsum = 0, possum = 0;
  for (size_t i = 0; i < asize; i++) {
    if (a[i] < 0) negsum += -(a[i]);
    else possum += a[i];
  } 
  *solnn = negsum;
  *solnp = possum;
  return 0;
}

//O(n) time and O(1) space.
//To show that this shuffle gives each of the n 
//elements equal likelihood to land in any of the n 
//indices, we could run 1000s of experiements and see
//that the number of times each of the n elements landed in 
//each of the indices is 1/n. This depends of how good
//rand() is
void shuffle(int* a, size_t asize) {
  if ( a== NULL || asize < 2) return;
  srand(time(NULL));
  size_t i = 0;
  size_t size = asize;
  while(i < size) {
    size_t idx = rand() % asize + i;
    swap(a[i], a[idx]);
    i++;
    asize--;
  }
}

//0: Found a common element
//1: Did not find any common element
int commonItem2(int* a, int* b, size_t asize, size_t bsize, int* soln) {
  int ret = -1;
  if (a == NULL || b == NULL || asize < 1 || bsize < 1) return ret;
  if (a[asize-1] >= b[0] && b[bsize-1] >= a[0]) {
    if (a[asize-1] == b[0]) {
      ret = 0;
      if (soln != NULL) *soln = b[0];
    }
    else if (b[bsize-1] == a[0]) {
      ret = 0;
      if (soln != NULL) *soln = a[0];
    }
    else {
      int* searchArray;
      size_t searchArraySize;
      int* keyArray;
      size_t keyArraySize;
      int initkey;
      if(a[asize-1] > b[bsize-1]) {
        searchArray = b; 
        searchArraySize = bsize;
        keyArray = a;
        keyArraySize = asize;
        initkey = b[bsize-1];
      } 
      else if (b[bsize-1] > a[asize-1]) {
        searchArray = a; 
        searchArraySize = asize;
        keyArray = b;
        keyArraySize = bsize;
        initkey = a[bsize-1];
      }
      else { //a[asize-1] == b[bsize-1]
        ret = 0;
        if (soln != NULL) *soln = b[bsize-1];
        return ret;
      }
      size_t rank;
      cout << "Looking for " << initkey << endl;
      int res = bSearch(keyArray, keyArraySize, initkey, &rank);
      cout << rank << endl;
      if (res == -1) ret = -1;
      else if (res == 0) {
        ret = 0;
        if (soln != NULL) *soln = keyArray[rank];
      }
      else { //Search miss
        size_t kidx = rank;
        while(rank > 0 && kidx > 0 && keyArray[kidx] >= searchArray[0]) {
          cout << "Looking for " << keyArray[kidx] << endl;
          res = bSearch(searchArray, searchArraySize, keyArray[kidx], &rank);
          cout << rank << endl;
          if (res == -1) {
            ret = -1;
            break;
          }
          else if (res == 0) {
            ret = 0;
            if (soln != NULL) *soln = searchArray[rank];
            break;
          }
          else {
            if (rank == 0) {
              ret = 1;
              break;
            }
            kidx--;
            searchArraySize = rank;
          }
        }         
        if (kidx == 0 && keyArray[kidx] >= searchArray[0]) {
          cout << "Looking for " << keyArray[kidx] << endl;
          res = bSearch(searchArray, rank, keyArray[0], &rank);
          if (res == -1) ret = 1;
          else if (res == 0) {
            ret = 0;
            if (soln != NULL) *soln = searchArray[rank];
          }
          else ret = 1;
        }
      }
    }
  }
  else ret = 1;
  return ret;
}

//O(n) time solution, O(n) space
int findMissingDupIn100(int* a, size_t asize, int* soln) {
  if ( a == NULL || !(asize == 99 || asize == 101) || soln == NULL) return -1;
  vector<bool> flag(100, false);
  if (asize == 99) {
    for (size_t i = 0; i < asize; i++) {
      flag[a[i]-1] = true;
    } 
    for (size_t i = 0; i < flag.size(); i++) {
      if (flag[i] == false) {
        *soln = i+1;
        break;
      }
    }
  }
  else if (asize == 101) {
    for (size_t i = 0; i < flag.size(); i++) {
      if (flag[a[i]-1] == true) {
        *soln = a[i];
        break;
      }
      else {
        flag[a[i]-1] = true;
      }
    }
  }
  return 0;
}

//O(nlogn) solution due to sort dominating. O(1) space
int findMissingDupIn100Sort(int* a, size_t asize, int* soln) {
  if ( a == NULL || !(asize == 99 || asize == 101) || soln == NULL) return -1;
  sort(a, a+asize);
  int lo = 0, hi = asize-1;
  while (lo < hi) {
    int mid = (hi+lo)/2;
    if (a[mid] == mid+1) {
      lo = mid+1;
    } 
    else {
      if (mid == 0) {
        *soln = lo+1;
        return 0;
      }
      hi = mid-1;
    }
  }
  //lo >= hi
  if (asize == 99) {
    if (a[lo] == lo+1) {
      *soln = lo+2; //a[lo]+1 
    }
    else {
      *soln = lo+1;
    }
  }
  else if (asize == 101)
    *soln = a[lo];
  return 0;
}

//O(nlogn) solution with O(1) space. Could use a hashset with O(n) time
//and O(n) space
int findDuplicates(int* a, size_t asize, vector<int>&  soln) {
  if ( a == NULL || asize < 2) return -1;
  sort(a, a+asize);
  int tmp = a[0];
  bool founddup = false;
  for (size_t i = 1; i < asize; i++) {
    if (tmp == a[i]) {
      if (!founddup) {
        founddup = true;
        soln.push_back(tmp);
      }
    }
    else {
      founddup = false;
      tmp = a[i];
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc < 2) return -1;
  size_t len = strtoul(argv[1], NULL, 10);
  int a[len];
  int b[len];
  srand(time(NULL));
  for(size_t i = 0; i < len; i++) {
    a[i] = rand() % (len*len) - ((len*len)/2);
    b[i] = rand() % (len*len) - ((len*len)/2) ;
  }
  sort(a, a+len);
  sort(b, b+len);
  for (size_t i = 0; i < len; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  for (size_t i = 0; i < len; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  int soln;
  if (!commonItem(a, b, len, len, &soln)) cout << "Found common item " << soln << endl;
  else cout << "No commonItem" << endl;
  if (!firstRepeatingHashSet(a, len, &soln)) cout << "Found firstRepeating item " << soln << endl;
  else cout << "No repeating Item" << endl;
  if (!firstRepeatingSort(a, len, &soln)) cout << "Found firstRepeating item " << soln << endl;
  else cout << "No repeating Item" << endl;
  if (!firstRepeatingBF(a, len, &soln)) cout << "Found firstRepeating item " << soln << endl;
  else cout << "No repeating Item" << endl;
  if (!alternateIncDec(a, len)) {
    for (auto i : a) 
      cout << i <<  " ";
    cout << endl;
  }
  size_t solnp, solnn;
  if (!sumPosNeg(a, len, &solnp, &solnn)) cout << "Sum of Positive and Negative elements are " << solnp << " " << solnn << endl;
  shuffle(b, len);
  for (auto i : b) 
    cout << i <<  " ";
  cout << endl;

  int unique100[101];
  for (size_t i = 1; i < 101; i++)
    unique100[i-1] = i;
  shuffle(unique100, 100);
  for (size_t i = 0; i < 99; i++)
    cout << unique100[i] <<  " ";
  cout << endl;
  if (!findMissingDupIn100(unique100, 99, &soln)) cout << "Missing element is " << soln << endl;
  else cout << "Bad arguments" << endl;  
  if (!findMissingDupIn100Sort(unique100, 99, &soln)) cout << "Missing element is " << soln << endl;
  else cout << "Bad arguments" << endl;  
  size_t randidx = rand() % 100;
  unique100[100] = unique100[randidx];
  shuffle(unique100, 101);
  for (size_t i = 0; i < 101; i++)
    cout << unique100[i] <<  " ";
  cout << endl;
  if (!findMissingDupIn100(unique100, 101, &soln)) cout << "Duplicate element is " << soln << endl;
  else cout << "Bad arguments" << endl;  
  if (!findMissingDupIn100Sort(unique100, 101, &soln)) cout << "Duplicate element is " << soln << endl;
  else cout << "Bad arguments" << endl;
  for (size_t i = 0; i < 100; i++)
    unique100[i] = rand() % 90 + 1;
  vector<int> sol;
  if (!findDuplicates(unique100, 100, sol)) {
    if (sol.size()) {
      cout << "Duplicate elements are ";
      for(auto i : sol) 
        cout << i << " ";
      cout << endl;
    }
  }
  else cout << "Bad arguments" << endl;  
  return 0;
}
