#include "container/bitset64.hpp"
#include "vector.hpp"

int main() {
  for (int n; n = in, !in.eof;) {
    Vector<int> res;
    for (auto i : Bitset64(n)) {
      res.emplace_back(1 << i);
    }
    res.output(" ");
  }
}
