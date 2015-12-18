#include "template.hpp"

int main() {
  int n, a;
  string k;
  cin >> n >> a >> k;
  --a;
  vector<int> b(n);
  for (int& i : b) cin >> i;
  for (int& i : b) --i;
  if (k.size() < 7u) {
    for (int i = 0, z = stoi(k); i < z; ++i) a = b[a];
    cout << a + 1 << endl;
    return 0;
  }
  vector<int> s(n, -1);
  int t = a, m = 0;
  for (; s[t] == -1; ++m) {
    s[t] = m;
    t = b[t];
  }
  int l = m - s[t];
  int x = 0;
  for (char c : k) x = (x * 10 + c - '0') % l;
  x -= s[t];
  while (x < 0) x += l;
  for (int i = 0; i < x; ++i) t = b[t];
  cout << t + 1 << endl;
}
