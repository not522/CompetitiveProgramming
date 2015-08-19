#pragma once
#include "template.hpp"

int levenshteinDistance(const string& a, const string& b) {
  vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
  for (size_t i = 1; i <= a.size(); ++i) dp[i][0] = i;
  for (size_t j = 1; j <= b.size(); ++j) dp[0][j] = j;
  for (size_t i = 0; i < a.size(); ++i) {
    for (size_t j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j];
      else dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
    }
  }
  return dp[a.size()][b.size()];
}
