#include "container/union_find.hpp"

int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  UnionFind uf(256);
  for (int i = 0; i < n; ++i) {
    if (isalpha(s1[i]) && isalpha(s2[i])) uf.unite(s1[i], s2[i]);
  }
  long long res = 1;
  for (char c = 'A'; c <= 'Z'; ++c) {
    if (s1.find(c) == string::npos && s2.find(c) == string::npos) continue;
    if (uf.find(c) != c) continue;
    int r = 10;
    if (uf.equal(s1[0], c) || uf.equal(s2[0], c)) r = 9;
    for (int i = 0; i < n; ++i) {
      if (isalpha(s1[i]) && isdigit(s2[i]) && uf.equal(s1[i], c)) r = 1;
      if (isdigit(s1[i]) && isalpha(s2[i]) && uf.equal(s2[i], c)) r = 1;
    }
    res *= r;
  }
  cout << res << endl;
}
