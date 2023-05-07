#include "container/bitset64.hpp"
#include "unordered_map.hpp"
#include "vector.hpp"

int n, m, res = 0;
Vector<Tuple<int, int>> x;
UnorderedMap<int, int64_t> mem;

int64_t solve(int bit) {
  if (bit == 0) {
    return 1;
  }
  if (mem.contains(bit)) {
    return mem[bit];
  }
  int64_t res = 0;
  for (int i : Bitset64(bit)) {
    if (x.all_of([&](const Tuple<int, int> &p) {
          return (bit & 1 << p.get<0>()) || p.get<1>() != i;
        })) {
      res += solve(bit ^ 1 << i);
    }
  }
  return mem[bit] = res;
}

int main() {
  n = in;
  m = in;
  x.resize(m);
  for (int i = 0; i < m; ++i) {
    x[i] = in;
    --x[i].get<0>();
    --x[i].get<1>();
  }
  cout << solve((1 << n) - 1) << endl;
}
