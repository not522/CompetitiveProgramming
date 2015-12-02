#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n), v;
  cin >> s;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) v.emplace_back(s[i] + s[j]);
  cout << *min_element(v.begin(), v.end()) << endl;
}
