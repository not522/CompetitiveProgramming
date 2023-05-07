#pragma once
#include "vector.hpp"

template <typename Weight, typename Value>
Value knapsack(Weight maxWeight, const Vector<Weight> &weight,
               const Vector<Value> &value) {
  Vector<Value> dp1(maxWeight + Weight(1)), dp2(maxWeight + Weight(1));
  for (int i = 0; i < weight.size(); ++i) {
    for (int w = 0; w <= maxWeight; ++w) {
      Weight ww = Weight(w) + weight[i];
      Value vv = dp1[w] + value[i];
      if (ww <= maxWeight && dp2[ww] < vv) {
        dp2[ww] = vv;
      }
    }
    dp1 = dp2;
  }
  return dp1[maxWeight];
}

template <typename Weight, typename Value = int64_t>
Vector<Value> knapsackCount(Weight maxWeight, const Vector<Weight> &weight) {
  Vector<Value> dp1(maxWeight + Weight(1)), dp2(maxWeight + Weight(1));
  dp1[0] = dp2[0] = 1;
  for (auto &w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight) {
        dp2[ww] += dp1[i];
      }
    }
    dp1 = dp2;
  }
  return dp1;
}

template <typename Weight>
Vector<bool> knapsackFill(Weight maxWeight, const Vector<Weight> &weight) {
  Vector<bool> dp1(maxWeight + Weight(1)), dp2(maxWeight + Weight(1));
  dp1[0] = dp2[0] = true;
  for (auto &w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight && dp1[i]) {
        dp2[ww] = true;
      }
    }
    dp1 = dp2;
  }
  return dp1;
}
