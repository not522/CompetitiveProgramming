#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in), res = 0;
  Vector<String> s(n);
  Vector<int> t(n);
  read(s, t);
  String x(in);
  bool sleep = false;
  for (int i = 0; i < n; ++i) {
    if (sleep) {
      res += t[i];
    }
    if (s[i] == x) {
      sleep = true;
    }
  }
  cout << res << endl;
}
