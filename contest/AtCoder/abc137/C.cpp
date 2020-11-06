#include "map.hpp"
#include "string.hpp"

int main() {
  int n(in);
  Vector<String> s(n, in);
  Map<String, int64_t> m;
  for (auto t : s) {
    ++m[t.sort()];
  }
  int64_t res = 0;
  for (const auto &itr : m) {
    cerr << itr.first << " " << itr.second << endl;
    res += itr.second * (itr.second - 1) / 2;
  }
  cout << res << endl;
}
