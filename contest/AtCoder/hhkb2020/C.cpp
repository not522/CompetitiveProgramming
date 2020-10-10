#include "set.hpp"

int main() {
  int n(in), k = 0;
  Set<int> s;
  for (int i = 0; i < n; ++i) {
    int p(in);
    s.emplace(p);
    for (; s.contains(k); ++k) {
    }
    cout << k << endl;
  }
}
