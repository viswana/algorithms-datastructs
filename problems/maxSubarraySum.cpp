/* \file maxSubarraySum.cpp
 * \brief Different ways to solve the max subarray sum problem.
 *
 * Given an array of numbers, find the contiguous subrange that has the maximum sum.
 * Print both the subrange and the sum.
 * E.g. 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7
 * Ans: (lo, hi, sum) = (7, 10, 43) 
 */

#include <iostream>
using namespace std;

/** \struct tuple
 *  \brief Return type of maxSubrangeSum function(s).
 * 
 *  The special value of -1, -1, 0 denotes the null set. If any subarray has a negative sum,
 *  This special value is returned.
 */

template <typename T>
struct tuple {
  int lo;
  int hi;
  T sum;
  tuple() {
    lo = -1, hi = -1, sum = 0;
  }
};

/** \fn int maxSubarraySum1(T const * const a, size_t len, tuple<T>& t)
 *  \brief A function that returns max subarray sum
 * 
 *  This algorithm goes through all combinations of array index ranges
 *  and keeps track of the max sum of each sub array range. It is O(n^3)
 */

template <typename T>
int maxSubarraySum1(T const * const a, size_t len, tuple<T>& t) {
  if (!a) return -1;
  t.lo = -1;
  t.hi = -1;
  t.sum = 0;
  for (size_t i = 0; i < len; i++) {
    for (size_t j = i ; j < len; j++) {
      T sum = 0;
      for (size_t k = i; k <= j; k++) {
	sum += a[k];
      }
      if (sum > t.sum) {
	t.lo = i;
	t.hi = j;
	t.sum = sum;
      }
    }
  }
  return 0;
}

/** \fn int maxSubarraySum2(T const * const a, size_t len, tuple<T>& t)
 *  \brief A function that returns max subarray sum
 * 
 *  This algorithm goes through all combinations of array index ranges
 *  and keeps track of the max sum of each sub array range. It is O(n^2)
 */

template <typename T>
int maxSubarraySum2(T const * const a, size_t len, tuple<T>& t) {
  if (!a) return -1;
  t.lo = -1;
  t.hi = -1;
  t.sum = 0;
  for (size_t i = 0; i < len; i++) {
    T sum = 0;
    for (size_t j = i; j < len; j++) {
      sum += a[j];
      if (sum > t.sum) {
	t.lo = i;
	t.hi = j;
	t.sum = sum;
      }
    }
  }
  return 0;
}

/** \fn int maxSubarraySum3(T const * const a, size_t len, tuple<T>& t)
 *  \brief A function that returns max subarray sum
 * 
 *  This algorithm uses divide and conquer to split the array in two. 
 *  Solve 2 subproblems, find the max subrange sum in the array crossing
 *  the two halves and finally taking the max of the 3 solutions. It 
 *  execution time is theta(n log n)
 */

template <typename T>
int maxSubarraySum3(T const * const a, size_t len, tuple<T>& t) {
  if (!a) return -1;
  t.lo = -1;
  t.hi = -1;
  t.sum = 0;
  if (len == 0) return 0;
  if (len == 1) {
    if (a[0] > 0) {
      t.sum = a[0];
      t.lo = 0;
      t.hi = 0;
    }
    return 0;
  }
  tuple<T> left, right, cross;
  size_t mid = (len-1)/2;
  maxSubarraySum3(a, mid+1, left);
  maxSubarraySum3(a+mid+1, len/2, right);
  cross.lo = -1;
  cross.hi = -1;
  cross.sum = 0;
  T leftSum = 0;
  for (int i = mid; i >= 0; i--) {
    leftSum += a[i];
    if (leftSum > cross.sum) {
      cross.sum = leftSum;
      cross.lo = i;
    }
  }
  T rightSum = cross.sum;
  for (size_t i = mid+1; i < len; i++) {
    rightSum += a[i];
    if (rightSum > cross.sum) {
      cross.sum = rightSum;
      cross.hi = i;
    }
  }
  t = left;
  if (right.sum > t.sum) {
    if (right.sum > cross.sum) {
      t = right;
    }
    else {
      t = cross;
    }
  }
  else {
    if (cross.sum > t.sum) {
      t = cross;
    }
  }
  return 0;
}

/** \fn int maxSubarraySum4(T const * const a, size_t len, tuple<T>& t)
 *  \brief A function that returns max subarray sum
 * 
 *  This algorithm uses the fact that the maxsubarray sum is either 
 *  in the subarray from a[1..j] or in the subarray including the j+1
 *  element a[i..j+1], 1 <= i <= j+1. It keeps track of the subarray sum 
 *  of a[i..j] to calculate sum of a[i..j+1] in constant time. It runs
 *  in theta(n) time.
 */

template <typename T>
int maxSubarraySum4(T const * const a, size_t len, tuple<T>& t) {
  if (!a) return -1;
  t.lo = -1, t.hi = -1, t.sum = 0;
  tuple<T> maxincend;
  for (size_t i = 0; i < len; i++) {
    maxincend.hi = i;
    T tmp = maxincend.sum + a[i];
    if (tmp < 0) {
      maxincend.lo = -1, maxincend.hi = -1, maxincend.sum = 0;
    }
    else {
      if (maxincend.lo == -1 && maxincend.sum == 0) {
	maxincend.lo = i;
      }
      maxincend.sum = tmp;
    }
    if (maxincend.sum > t.sum) {
      t = maxincend;
    }
  }
  return 0;
}

int main() {
  int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  //int a[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
  tuple<int> t;
  maxSubarraySum4(a, sizeof(a)/sizeof(int), t);
  cout << t.lo << " " << t.hi << " " << t.sum << endl;
  return 0;
}
