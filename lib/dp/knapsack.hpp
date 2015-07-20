#pragma once
#include "template.hpp"

template<typename Weight, typename Value> Value knapsack(Weight maxWeight, const vector<Weight>& weight, const vector<Value>& value, Value init = 0, function<Weight(Weight, Weight)> func = plus<Weight>()) {
  vector<Value> dp(maxWeight + 1, 0);
  dp[0] = init;
  for (size_t i = 0; i < weight.size(); ++i) {
    for (auto w = maxWeight; w >= weight[i]; --w) {
      dp[w] = max(dp[w], func(dp[w - weight[i]], value[i]));
    }
  }
  return dp[maxWeight];
}
