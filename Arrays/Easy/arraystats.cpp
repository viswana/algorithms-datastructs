#include <iostream>
#include <cstdlib>

using namespace std;

int SumArray(long long a[], size_t s, long long* soln) {
  int ret = -1;
  if (a != NULL && s > 0 && soln != NULL) {
    ret = 0;
    *soln = 0;
    for (size_t i = 0; i < s; i++) 
      *soln += a[i];
  }
  return ret;
}

int ArrayMean(long long a[], size_t s, double* soln) {
  long long sum;
  int ret;
  ret = SumArray(a, s, &sum);
  if(ret == 0) *soln = (double)sum/s;
  return ret; 
} 

int SmallLarge(long long a[], size_t s, long long *soln) {
  int ret = -1;
  if (a != NULL && s > 0 && soln != NULL) {
    soln[0] = a[0];
    soln[1] = a[0];
    for (size_t i = 1; i < s; i++) {
      if (a[i] < soln[0])
        soln[0] = a[i];
      if (a[i] > soln[1])
        soln[1] = a[i];  
    }
    ret = 0;
  }
  return ret;
}

int partition(long long a[], size_t s, size_t* rank) {
  if (a == NULL || s == 0 || rank == NULL) return -1;
  long long pivot = a[0];
  size_t i = 1, j = 1;
  while (j < s) {
    if (a[j] < pivot) {
      if (i < j) {
        long long temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
      i++;
      j++;
    }
    else {
      j++;
    }
  }
  i--;
  if (i > 0) {
    long long temp = a[i];
    a[i] = a[0];
    a[0] = temp;
  }
  *rank = i;
  return 0;
}

void shuffle(long long a[], size_t s) {
  if (a != NULL && s > 1) {
    srand(time(NULL));
    for (size_t i = 0; i < s; i++) {
      size_t idx = rand() % (s-i);
      long long temp = a[s-1-i];
      a[s-1-i] = a[idx];
      a[idx] = temp;
    }
  }
}

int GetNthLargest(long long a[], size_t s, size_t rank, long long* soln) {
  int ret = -1;
  if (a != NULL && s > 0 && rank < s && soln != NULL) {
    shuffle(a, s);
    size_t opp_rank = s-1-rank;
    size_t prank;
    while(partition(a, s, &prank) == 0) {
      if(opp_rank == prank) {
        *soln = a[prank];
        break;  
      }
      else if (prank > opp_rank) {
        s = prank;
      }
      else {
        a += prank+1;
        s -= prank+1;
        opp_rank -= prank+1;
      }
    }
    ret = 0;
  }
  return ret;
}

void QuickSort(long long a[], size_t s) {
  if (a == NULL || s < 2) return;
  size_t rank;
  shuffle(a, s);
  if (partition(a, s, &rank) == 0) {
    QuickSort(a, rank);
    QuickSort(a+rank+1, s-(rank+1));
  }
}

int UniqueElements(long long a[], size_t s, bool* ret) {
  if (a == NULL || s < 1 || ret == NULL) return -1;
  QuickSort(a, s);
  long long t = a[0];
  for (size_t i = 1; i < s; i++) {
    if (t == a[i]) {
      *ret = false;
      return 0;
    }
    t = a[i]; 
  } 
  *ret = true;
  return 0;
}

int sanitizeCharArray(char* input, size_t isize, const char* forbidden, size_t fsize) {
  if (input == NULL || isize < 1) return -1;
  if (forbidden == NULL || fsize < 1) return 0;
  else {
    size_t f = 0;
    while(f < fsize) {
      size_t i = 0;
      while (i < isize) {
        if (input[i] == forbidden[f]) {
          size_t j = i;
          while (j < isize-1) {
            input[j] = input[j+1];
            j++;
          }
          isize--;
        }
        else {
          i++;
        }
      }
      f++;
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc < 2) return -1;
  srand(time(NULL));
  unsigned long len = strtoul(argv[1], NULL, 10);
  long long a[len];
  for (size_t i = 0; i < len; i++) {
    //Expected ~50% chance of duplicates
    a[i] = rand() % (len*len) + 1;
    cout << a[i] << " ";
  }
  cout << endl;
  long long soln;
  double mean;
  long long smallLarge[2];
  if (SumArray(a, len, &soln) == 0)
    cout << "Sum : " << soln << endl;
  else 
    cout << "Bad input" << endl;
  if (ArrayMean(a, len, &mean) == 0)
    cout << "Mean : " << mean  << endl;
  else 
    cout << "Bad input" << endl;
  if (SmallLarge(a, len, smallLarge) == 0)
    cout << "Min: " << smallLarge[0] << " Max: " << smallLarge[1]  << endl;
  else 
    cout << "Bad input" << endl;
  if (GetNthLargest(a, len, len/2, &soln) == 0) 
    cout << "Median : " << soln  << endl;
  else
    cout << "Bad input" << endl;
  if (GetNthLargest(a, len, 3, &soln) == 0) 
    cout << "4th largest : " << soln  << endl;
  else
    cout << "Bad input" << endl;

  bool isUnique;
  if (UniqueElements(a, len, &isUnique) == 0) 
    cout << "Array Elements are " << (isUnique ? "Unique" : "Non-Unique")  << endl;
  else
    cout << "Bad input" << endl;

  cout << "Sorted input list" << endl;
  for(size_t i = 0; i < len; i++)
    cout << a[i] << " ";
  cout << endl;
  
  char input[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
  char forbidden[] = "cLi";
  if(sanitizeCharArray(input, sizeof(input), forbidden, sizeof(forbidden)) == 0) 
    cout << input << endl;
  else
    cout << "Bad input" << endl;
  return 0;
}
