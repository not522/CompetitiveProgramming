#pragma once
#include "template.hpp"

template<class Value, bool rangeAdd = false> class CumulativeSum2D {
private:
  struct RangeValue {
    int i, j, y, x;
    Value v;
    RangeValue(int i, int j, int y, int x, Value v) : i(i), j(j), y(y), x(x), v(v) {}
  };

  vector<vector<Value>> val;
  vector<RangeValue> rangeValue;

public:
  CumulativeSum2D() {}

  CumulativeSum2D(int n, int m) : val(n + 1, vector<Value>(m + 1, Value(0))) {}
  
  template<typename T> CumulativeSum2D(T v) {
    int n = v.size();
    int m = v.front().size();
    for (int i = 0; i < n + 1; ++i) val.emplace_back(m + 1, Value(0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        val[i + 1][j + 1] = val[i][j + 1] + val[i + 1][j] - val[i][j] + v[i][j];
      }
    }
  }

  void add(int i, int j, Value v) {
    add(i, j, i + 1, j + 1, v);
  }

  void add(int i, int j, int y, int x, Value v) {
    rangeValue.emplace_back(i, j, y, x, v);
  }

  // [(i,j), (y,x))
  Value sum(int i, int j, int y, int x) {
    if (rangeAdd && !rangeValue.empty()) {
      int n = val.size() - 1;
      int m = val.front().size() - 1;
      for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            val[i + 1][j + 1] = val[i + 1][j + 1] - val[i][j + 1] - val[i + 1][j] + val[i][j];
          }
        }
      }
      for (const auto& v : rangeValue) {
        val[v.i + 1][v.j + 1] += v.v;
        if (v.y < n) val[v.y + 1][v.j + 1] -= v.v;
        if (v.x < m) val[v.i + 1][v.x + 1] -= v.v;
        if (v.y < n && v.x < m) val[v.y + 1][v.x + 1] += v.v;
      }
      for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            val[i + 1][j + 1] += val[i][j + 1] + val[i + 1][j] - val[i][j];
          }
        }
      }
      rangeValue.clear();
    }
    return val[y][x] - val[i][x] - val[y][j] + val[i][j];
  }

  Value value(int i, int j) {
    return sum(i, j, i + 1, j + 1);
  }
};
