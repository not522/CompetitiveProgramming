#include "template.hpp"

int main() {
  int64_t w, h, n;
  cin >> w >> h >> n;
  set<int> a, b;
  for (int i = 0; i < n; ++i) {
    int s, k;
    cin >> s >> k;
    a.insert(s);
    b.insert(k);
  }
  cout << a.size() * h + b.size() * w - a.size() * b.size() - n << endl;
}
