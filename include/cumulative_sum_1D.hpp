#pragma once
#include "vector.hpp"

template<typename Value> class CumulativeSum1D {
private:
  struct RangeValue {
    int i, j;
    Value v;
    RangeValue(int i, int j, Value v) : i(i), j(j), v(v) {}
  };

  Vector<Value> val;
  Vector<RangeValue> rangeValue;

public:
  CumulativeSum1D(int n) : val(n + 2) {}

  CumulativeSum1D(size_t n) : val(n + 2) {}

  template<typename T> CumulativeSum1D(T v) : val(v.size() + 2) {
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
    if (!rangeValue.empty()) {
      adjacent_difference(val.begin(), val.end(), val.begin());
      adjacent_difference(val.begin(), val.end(), val.begin());
      for (const auto& v : rangeValue) {
        val[v.i + 1] += v.v;
        val[v.j + 1] -= v.v;
      }
      partial_sum(val.begin(), val.end(), val.begin());
      partial_sum(val.begin(), val.end(), val.begin());
      rangeValue.clear();
    }
    return val[j] - val[i];
  }

  Value value(int i) {
    return sum(i, i + 1);
  }

  Value max() {
    auto res = std::numeric_limits<Value>::min();
    for (int i = 0; i < int(val.size()) - 2; ++i) chmax(res, value(i));
    return res;
  }
};
