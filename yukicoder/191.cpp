#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  cin >> c;
  int sum = accumulate(c);
  cout << 30 * count_if(c.begin(), c.end(), [&](int i){return i <= sum / 10;}) << endl;
}
