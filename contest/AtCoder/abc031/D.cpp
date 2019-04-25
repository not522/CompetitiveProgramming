#include "set.hpp"
#include "string.hpp"
#include "vector.hpp"

int k, n;
Vector<String> v, w;
Vector<int> l(10);

bool solve(int a) {
  if (a > k) {
    Vector<Set<String>> t(k);
    for (int i = 0; i < v.size(); ++i) {
      int x = 0;
      for (char c : v[i]) {
        if (w[i].size() < x + l[c - '1']) {
          return false;
        }
        t[c - '1'].insert(w[i].substr(x, l[c - '1']));
        x += l[c - '1'];
      }
      if (x != int(w[i].size())) {
        return false;
      }
    }
    if (t.any_of([](const Set<String> &s) { return s.size() != 1; })) {
      return false;
    }
    for (auto s : t) {
      cout << *s.begin() << endl;
    }
    return true;
  }
  for (int i = 1; i <= 3; ++i) {
    l[a] = i;
    if (solve(a + 1)) {
      return true;
    }
  }
  return false;
}

int main() {
  k = in;
  n = in;
  v = Vector<String>(n);
  w = Vector<String>(n);
  read(v, w);
  solve(0);
}
