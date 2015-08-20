#include "math/prime.hpp"

int main() {
  Prime prime(10000);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  multiset<int> s(a.begin() + 1, a.end());
  vector<multiset<int>> v(10001);
  for (int i : s) {
    for (auto d : prime.divisor(i)) v[d].insert(i);
  }
  int p = a[0];
  while (!s.empty()) {
    int next = -1, lcm = numeric_limits<int>::max();
    for (auto d : prime.divisor(p)) {
      if (v[d].empty()) continue;
      int l = p * *(v[d].begin()) / d;
      if (lcm > l) {
        next = *(v[d].begin());
        lcm = l;
      }
    }
    cout << p << " ";
    p = next;
    s.erase(s.find(p));
    for (auto d : prime.divisor(p)) v[d].erase(v[d].find(p));
  }
  cout << p << endl;
}
