#include "vector.hpp"

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(4);
  for (char c : s) ++a[c - '1'];
  cout << max(a) << " " << min(a) << endl;
}
