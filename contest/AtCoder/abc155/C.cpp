#include "map.hpp"
#include "string.hpp"

int main() {
  int n(in), mx = 0;
  Map<String, int> m;
  for (int i = 0; i < n; ++i) {
    String s(in);
    ++m[s];
    chmax(mx, m[s]);
  }
  Vector<String> res;
  for (const auto &[s, c] : m) {
    if (c == mx) {
      res.emplace_back(s);
    }
  }
  res.output();
}
