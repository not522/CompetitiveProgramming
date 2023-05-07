#pragma once
#include "vector.hpp"

template <typename Weight, typename Value, bool strict = false>
Value unboundedKnapsack(Weight maxWeight, const Vector<Weight> &weight,
                        const Vector<Value> &value) {
  Vector<Value> dp(maxWeight + 1);
  if (strict) {
    fill(dp.begin() + 1, dp.end(), -inf<Value>());
  }
  for (int i = 0; i < weight.size(); ++i) {
    for (int w = 0; w <= maxWeight; ++w) {
      if (strict && dp[w] == -inf<Value>()) {
        continue;
      }
      Weight ww = Weight(w) + weight[i];
      if (ww <= maxWeight) {
        chmax(dp[ww], dp[w] + value[i]);
      }
    }
  }
  return dp.back();
}

template <typename Weight, typename Value = int64_t>
Vector<Value> unboundedKnapsackCount(Weight maxWeight,
                                     const Vector<Weight> &weight) {
  Vector<Value> dp(maxWeight + 1);
  dp[0] = 1;
  for (auto &w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight) {
        dp[ww] += dp[i];
      }
    }
  }
  return dp;
}

template <typename Weight>
Vector<bool> unboundedKnapsackFill(Weight maxWeight,
                                   const Vector<Weight> &weight) {
  Vector<bool> dp(maxWeight + 1);
  dp[0] = true;
  for (auto &w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight && dp[i]) {
        dp[ww] = true;
      }
    }
  }
  return dp;
}
