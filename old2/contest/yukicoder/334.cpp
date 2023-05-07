#include "unordered_map.hpp"
#include "vector.hpp"

int n;
Vector<int> a;
UnorderedMap<int, bool> mem;

bool solve(int bit) {
  if (mem.count(bit)) {
    return mem[bit];
  }
  for (int i = 0; i < n; ++i) {
    if (bit & (1 << i)) {
      continue;
    }
    for (int j = i + 1; j < n; ++j) {
      if (bit & (1 << j)) {
        continue;
      }
      if (a[i] == a[j]) {
        continue;
      }
      for (int k = j + 1; k < n; ++k) {
        if (bit & (1 << k)) {
          continue;
        }
        if (a[i] == a[k] || a[j] == a[k]) {
          continue;
        }
        if (max({a[i], a[j], a[k]}) != a[j] &&
            min({a[i], a[j], a[k]}) != a[j]) {
          continue;
        }
        if (!solve(bit ^ (1 << i) ^ (1 << j) ^ (1 << k))) {
          if (bit == 0) {
            cout << i << " " << j << " " << k << endl;
          }
          return mem[bit] = true;
        }
      }
    }
  }
  return mem[bit] = false;
}

int main() {
  n = in;
  a = Vector<int>(n, in);
  solve(0);
  if (!mem[0]) {
    cout << -1 << endl;
  }
}
