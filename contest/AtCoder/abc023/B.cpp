#include "map.hpp"
#include "string.hpp"

int main() {
  Map<String, int> m;
  String k = "b";
  for (int i = 1; i < 100; ++i) {
    int n = m.size();
    m[k] = n;
    if (i % 3 == 1) {
      k = "a" + k + "c";
    }
    if (i % 3 == 2) {
      k = "c" + k + "a";
    }
    if (i % 3 == 0) {
      k = "b" + k + "b";
    }
  }
  int n(in);
  (void)n;
  String s(in);
  if (m.contains(s)) {
    cout << m[s] << endl;
  } else {
    cout << -1 << endl;
  }
}
