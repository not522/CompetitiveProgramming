#include "set.hpp"
#include "string.hpp"

int main() {
  setBoolName("SUCCESS", "FAILURE");
  String b(in);
  int n(in);
  String a(in);
  Set<String> s;
  s.insert(a);
  for (int i = 0; i < min(n, 4); ++i) {
    Set<String> t;
    for (String ss : s) {
      swap(ss[0], ss[1]);
      t.insert(ss);
      swap(ss[0], ss[1]);
      swap(ss[1], ss[2]);
      t.insert(ss);
    }
    s = t;
  }
  cout << !s.contains(b) << endl;
}
