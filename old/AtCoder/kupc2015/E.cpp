#include "golden_section_search.hpp"

void solve() {
  long double h, w;
  cin >> h >> w;
  if (h > w) swap(h, w);
  auto f = [&](long double x) {return -min(sqrt(w * w + (h - x) * (h - x)), sqrt(x * x + ((h * h + w * w - x * x) / 2 / w) * ((h * h + w * w - x * x) / 2 / w)));};
  cout << -f(goldenSectionSearch(f, 0, h)) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
