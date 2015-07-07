#pragma once
#include "template.hpp"

template<typename Value, bool rangeAdd = false> class CumulativeSum1D {
private:
  struct RangeValue {
    int i, j;
    Value v;
    RangeValue(int i, int j, Value v) : i(i), j(j), v(v) {}
  };

  vector<Value> val;
  vector<RangeValue> rangeValue;

public:
  CumulativeSum1D(int n) : val(n + 1, Value(0)) {}

  template<class T> CumulativeSum1D(T v) {
    val.resize(v.size() + 1, Value(0));
    partial_sum(v.begin(), v.end(), val.begin() + 1);
  }

  void add(int i, Value v) {
    add(i, i + 1, v);
  }

  void add(int i, int j, Value v) {
    rangeValue.emplace_back(i, j, v);
  }

  // [i,j)
  Value sum(int i, int j) {
    if (rangeAdd && !rangeValue.empty()) {
      vector<Value> diff(val.size());
      adjacent_difference(val.begin(), val.end(), diff.begin());
      adjacent_difference(diff.begin(), diff.end(), diff.begin());
      for (const auto& v : rangeValue) {
        diff[v.i + 1] += v.v;
        diff[v.j + 1] -= v.v;
      }
      partial_sum(diff.begin(), diff.end(), val.begin());
      partial_sum(val.begin(), val.end(), val.begin());
      rangeValue.clear();
    }
    return val[j] - val[i];
  }

  Value value(int i) {
    return sum(i, i + 1);
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
