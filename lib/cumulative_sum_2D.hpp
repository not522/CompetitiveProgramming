#pragma once
#include "template.hpp"

template<class T> class CumulativeSum2D {
private:
  typedef typename T::value_type::value_type Value;

  vector<vector<Value>> value;

public:
  CumulativeSum2D(T v) {
    int n = v.size();
    int m = v.front().size();
    for (int i = 0; i < n + 1; ++i) value.emplace_back(m + 1, (Value)0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        value[i + 1][j + 1] = value[i][j + 1] + value[i + 1][j] - value[i][j] + v[i][j];
      }
    }
  }

  // [(i,j), (y,x))
  Value sum(int i, int j, int y, int x) {
    return value[y][x] - value[i][x] - value[y][j] + value[i][j];
  }
};
