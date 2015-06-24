#pragma once
#include "template.hpp"

template<typename T> class CumulativeSum1D {
private:
  typedef typename T::value_type::value_type Value;

  vector<Value> value;

public:
  CumulativeSum1D(T v) {
    int n = v.size();
    value.resize(n + 1, (Value)0);
    for (int i = 0; i < n; ++i) value[i + 1] = value[i] + v[i];
  }

  // [i,j)
  Value sum(int i, int j) {
    return value[j] - value[i];
  }
};

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
