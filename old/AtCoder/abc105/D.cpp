#include "template.hpp"

int main() {
  int n, m, t = 0;
  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  unordered_map<int, int> mp;
  int64_t res = 0;
  mp[0] = 1;
  for (int i : a) {
    t = (t + i) % m;
    res += mp[t];
    ++mp[t];
  }
  cout << res << endl;
}
