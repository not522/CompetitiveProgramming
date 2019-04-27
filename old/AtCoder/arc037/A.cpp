#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> m(n);
  for (int& i : m) cin >> i;
  cout << accumulate(m.begin(), m.end(), 0, [](int a, int b){return a + max(0, 80 - b);}) << endl;
}
