#pragma once
#include "bit_operation.hpp"

class NQueens {
private:
  int n;
  vector<vector<int>> res;
  vector<int> tmp;

  void solve(int m, int a, int b, int c) {
    if (n == m) {
      res.emplace_back(tmp);
      return;
    }
    for (int i = 0; i < n; ++i) {
      int bit = 1 << i;
      if (bit & (a | b | c)) continue;
      tmp.emplace_back(i);
      solve(m + 1, (a | bit) << 1, b | bit, (c | bit) >> 1);
      tmp.pop_back();
    }
  }

public:
  NQueens(int n) : n(n) {}

  vector<vector<int>> solve() {
    res.clear();
    solve(0, 0, 0, 0);
    return res;
  }
};
