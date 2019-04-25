#include "string.hpp"
#include "vector.hpp"

int main() {
  int n(in), a(in);
  String k(in);
  --a;
  Vector<int> b(n, in);
  b -= 1;
  if (k.size() < 7) {
    for (int i = 0, z = stoi(k); i < z; ++i) {
      a = b[a];
    }
    cout << a + 1 << endl;
    return 0;
  }
  Vector<int> s(n, -1);
  int t = a, m = 0;
  for (; s[t] == -1; ++m) {
    s[t] = m;
    t = b[t];
  }
  int l = m - s[t], x = 0;
  for (char c : k) {
    x = (x * 10 + c - '0') % l;
  }
  x -= s[t];
  while (x < 0) {
    x += l;
  }
  for (int i = 0; i < x; ++i) {
    t = b[t];
  }
  cout << t + 1 << endl;
}
