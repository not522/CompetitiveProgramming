#include "set.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), a(in), b(in), k(in);
  (void)n;
  Set<int> s{a, b};
  for (int i = 0; i < k; ++i) {
    s.emplace(in);
  }
  cout << (s.size() == k + 2) << endl;
}
