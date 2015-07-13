#include "dp/lis.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int& i : c) cin >> i;
  LIS<vector<int>, int> lis(c);
  cout << n - lis.solve() << endl;
}
