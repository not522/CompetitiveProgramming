#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int t = 0;
  vector<int> v;
  for (char c : s) {
    if (c == '+') ++t;
    if (c == '-') --t;
    if (c == 'M') v.emplace_back(t);
  }
  sort(v.begin(), v.end());
  for (unsigned i = 0; i < v.size() / 2; ++i) v[i] *= -1;
  cout << accumulate(v.begin(), v.end(), 0ll) << endl;
}
