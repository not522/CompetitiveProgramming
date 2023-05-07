#include "string.hpp"

int main() {
  String a(in);
  for (char c = 'a'; c <= 'z'; ++c) {
    a += c;
  }
  a = a.reverse() + char('z' + 1);
  Vector<Tuple<int, int>> mem(27, makeTuple(0, -1));
  Vector<int> p(a.size());
  for (int i = 0; i < a.size(); ++i) {
    int k = inf<int>();
    Tuple<int, int> m;
    for (int j = 0; j < 26; ++j) {
      if (chmin(k, mem[j].get<0>())) {
        m = mem[j];
      }
    }
    p[i] = m.get<1>();
    mem[a[i] - 'a'] = makeTuple(m.get<0>() + 1, i);
  }
  for (int t = p.back(); t != -1; t = p[t]) {
    cout << a[t];
  }
  cout << endl;
}
