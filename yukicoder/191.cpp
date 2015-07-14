#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int& i : c) cin >> i;
  int sum = accumulate(c.begin(), c.end(), 0);
  cout << 30 * count_if(c.begin(), c.end(), [&](int i){return i <= sum / 10;}) << endl;
}
