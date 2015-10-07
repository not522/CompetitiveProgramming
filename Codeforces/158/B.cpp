#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int& i : s) cin >> i;
  int sum = accumulate(s.begin(), s.end(), 0);
  int c1 = count(s.begin(), s.end(), 1);
  int c3 = count(s.begin(), s.end(), 3);
  cout << ceil(sum + max(c3 - c1, 0), 4) << endl;
}
