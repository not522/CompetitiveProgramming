#include "bit_operation.hpp"
#include "vector.hpp"

int main() {
  int l(in), n = most_bit(l) + 1;
  Vector<Tuple<int, int, int>> edges;
  for (int i = 0; i < n - 1; ++i) {
    edges.emplace_back(i + 1, i + 2, 0);
    edges.emplace_back(i + 1, i + 2, 1 << i);
  }
  int k = 1 << (n - 1);
  while (l > k) {
    int m = most_bit(l - k);
    edges.emplace_back(m + 1, n, k);
    k += 1 << m;
  }
  cout << n << " " << edges.size() << endl;
  for (const auto &[i, j, k] : edges) {
    cout << i << " " << j << " " << k << endl;
  }
}
