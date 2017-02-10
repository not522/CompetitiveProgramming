#include "vector.hpp"
#include "container/bit_iterator.hpp"

int n, m, res = 0;
vector<pair<int, int>> x;
unordered_map<int, int64_t> mem;

int64_t solve(int bit) {
  if (bit == 0) return 1;
  if (mem.count(bit)) return mem[bit];
  int64_t res = 0;
  for (int i : BitIterator(bit)) {
    if (all_of(x, [&](pair<int, int> p){return (bit & 1 << p.first) || p.second != i;})) res += solve(bit ^ 1 << i);
  }
  return mem[bit] = res;
}

int main() {
  cin >> n >> m;
  x.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i].first >> x[i].second;
    --x[i].first;
    --x[i].second;
  }
  cout << solve((1 << n) - 1) << endl;
}
