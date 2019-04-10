#include "set.hpp"
#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<int> a(n, in);
  Set<int> s;
  for (int i = 0; i < n; ++i) {
    if (s.count(a[i])) {
      ++res;
    }
    s.emplace(a[i]);
  }
  cout << res << endl;
}
