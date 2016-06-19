#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  cin >> a;
  map<string, int> m;
  for (auto s : a) {
    ++m[s];
    if (m[s] > (n + 1) / 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
