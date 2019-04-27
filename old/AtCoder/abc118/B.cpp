#include "set.hpp"
#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  Set<int> s;
  for (int i = 0; i < m; ++i) s.emplace(i + 1);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    Vector<int> a(k, cin);
    s &= a;
  }
  cout << s.size() << endl;
}
