#include "set.hpp"

int main() {
  int64_t w(in), h(in), n(in);
  Set<int> a, b;
  for (int i = 0; i < n; ++i) {
    a.emplace(in);
    b.emplace(in);
  }
  cout << a.size() * h + b.size() * w - a.size() * b.size() - n << endl;
}
