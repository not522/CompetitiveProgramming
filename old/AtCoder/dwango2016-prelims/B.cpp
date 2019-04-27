#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> k(n - 1);
  cin >> k;
  cout << k[0] << " ";
  for (int i = 0; i < n - 2; ++i) cout << min(k[i], k[i + 1]) << " ";
  cout << k.back() << endl;
}
