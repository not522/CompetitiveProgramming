#include "binary_search.hpp"
#include "minmax.hpp"
#include "vector.hpp"

int n;
vector<int64_t> b(1);

int64_t res;
vector<vector<int>> mem;

int negamax(int k, int turn) {
  if (k == n) return 0;
  if (mem[k][turn == 1] != -1e9) return mem[k][turn == 1];
  int r = -1e9;
  for (int i = k + 1; i <= n; ++i) {
    chmax(r, -negamax(i, -turn) + (b[i] - b[k] >= res ? turn : -turn));
  }
  return mem[k][turn == 1] = r;
}

bool solve(int64_t r) {
  res = r;
  mem = vector<vector<int>>(n, vector<int>(2, -1e9));
  int a = negamax(0, 1);
  return a >= 0;
}

int main() {
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) b.emplace_back(a[i] + b[i]);
  cout << binarySearch(solve, accumulate(a), 1e15) << endl;
}
