#include "template.hpp"

int k, n;
vector<string> v, w;
int l[10];

bool solve(int a) {
  if (a > k) {
    vector<set<string>> t(k);
    for (unsigned i = 0; i < v.size(); ++i) {
      int x = 0;
      for (char c : v[i]) {
        if (int(w[i].size()) < x + l[c - '1']) return false;
        t[c - '1'].insert(w[i].substr(x, l[c - '1']));
        x += l[c - '1'];
      }
      if (x != int(w[i].size())) return false;
    }
    if (any_of(t.begin(), t.end(), [](set<string> s){return s.size() != 1u;})) return false;
    for (auto s : t) cout << *s.begin() << endl;
    return true;
  }
  for (int i = 1; i <= 3; ++i) {
    l[a] = i;
    if (solve(a + 1)) return true;
  }
  return false;
}

int main() {
  cin >> k >> n;
  v.resize(n);
  w.resize(n);
  for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
  solve(0);
}
