#pragma once
#include "string.hpp"
#include "vector.hpp"

int levenshteinDistance(const String &a, const String &b) {
  Vector<Vector<int>> dp(a.size() + 1, Vector<int>(b.size() + 1));
  for (int i = 1; i <= a.size(); ++i) {
    dp[i][0] = i;
  }
  for (int j = 1; j <= b.size(); ++j) {
    dp[0][j] = j;
  }
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) {
        dp[i + 1][j + 1] = dp[i][j];
      } else {
        dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
      }
    }
  }
  return dp[a.size()][b.size()];
}
