#include "set.hpp"
#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<int> a(n, in);
  for (int i = 0; i < n - 2; ++i) {
    auto itr = a.begin() + i;
    if (Set<int>(itr, itr + 3).size() != 3) {
      continue;
    }
    auto m = minmax_element(itr, itr + 3);
    if (m.first != itr && m.second != itr) {
      ++res;
    } else if (m.first != itr + 2 && m.second != itr + 2) {
      ++res;
    }
  }
  cout << res << endl;
}
