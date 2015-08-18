#pragma once
#include "template.hpp"

template<typename Weight, typename Value, bool strict = false> Value unboundedKnapsack(Weight maxWeight, const vector<Weight>& weight, const vector<Value>& value) {
  constexpr Value IMP = numeric_limits<Value>::min();
  vector<Value> dp(maxWeight + Weight(1));
  if (strict) fill(dp.begin() + 1, dp.end(), IMP);
  for (size_t i = 0; i < weight.size(); ++i) {
    for (int w = 0; w <= maxWeight; ++w) {
      if (strict && dp[w] == IMP) continue;
      Weight ww = Weight(w) + weight[i];
      Value vv = dp[w] + value[i];
      if (ww <= maxWeight && dp[ww] < vv) dp[ww] = vv;
    }
  }
  return dp[maxWeight];
}

template<typename Weight, typename Value = long long> vector<Value> knapsackCount(Weight maxWeight, const vector<Weight>& weight) {
  vector<Value> dp(maxWeight + Weight(1));
  dp[0] = 1;
  for (auto& w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight) dp[ww] += dp[i];
    }
  }
  return dp;
}

template<typename Weight> vector<bool> unboundedKnapsackFill(Weight maxWeight, const vector<Weight>& weight) {
  vector<bool> dp(maxWeight + Weight(1));
  dp[0] = true;
  for (auto& w : weight) {
    for (int i = 0; i <= maxWeight; ++i) {
      Weight ww = Weight(i) + w;
      if (ww <= maxWeight && dp[i]) dp[ww] = true;
    }
  }
  return dp;
}
