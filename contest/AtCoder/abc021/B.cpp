#include "template.hpp"

int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  set<int> s = {a, b};
  for (int i = 0; i < k; ++i) {
    int p;
    cin >> p;
    s.insert(p);
  }
  cout << (int(s.size()) == k + 2 ? "YES" : "NO") << endl;
}
