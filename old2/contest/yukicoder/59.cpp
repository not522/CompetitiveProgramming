#include "container/bit.hpp"

int main() {
  int n(in), k(in);
  BIT<int> bit(1000001);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int w(in);
    if (w > 0) {
      if (bit.sum(w, 1000001) >= k) {
        continue;
      }
      bit.add(w, 1);
      ++res;
    } else {
      if (bit.sum(-w, -w + 1) == 0) {
        continue;
      }
      bit.add(-w, -1);
      --res;
    }
  }
  cout << res << endl;
}
