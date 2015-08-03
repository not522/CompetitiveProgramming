#include "template.hpp"

int main() {
  string a, b;
  int n;
  cin >> b >> n >> a;
  set<string> s;
  s.insert(a);
  for (int i = 0; i < min(n, 4); ++i) {
    set<string> t;
    for (string ss : s) {
      swap(ss[0], ss[1]);
      t.insert(ss);
      swap(ss[0], ss[1]);
      swap(ss[1], ss[2]);
      t.insert(ss);
    }
    s = t;
  }
  cout << (s.count(b) ? "FAILURE" : "SUCCESS") << endl;
}
