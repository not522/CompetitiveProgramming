#include "binary_search.hpp"

int main() {
  int cnt = 0;
  auto f = [&](int m) {
    cout << "? " << m - cnt << endl;
    ++cnt;
    return int(in) >= 0;
  };
  auto res = binarySearch(f, 10, f(100) ? 1e9 + 1 : 101);
  cout << "! " << res << endl;
}
