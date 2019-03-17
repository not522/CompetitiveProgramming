#include "container/bitset64.hpp"
#include "vector.hpp"

int main() {
  for (int n; cin >> n;) {
    Vector<int> res;
    for (auto i : Bitset64(n)) {
      res.emplace_back(1 << i);
    }
    res.output(' ');
  }
}
