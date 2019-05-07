#include "vector.hpp"

template <typename T> T maximumSubarray(const Vector<T> &v) {
  int sum = 0, res = v[0];
  for (T i : v) {
    sum = max(sum + i, i);
    chmax(res, sum);
  }
  return res;
}
