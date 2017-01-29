#include "vector.hpp"

int main() {
  vector<int> c(5);
  cin >> c;
  int sum = accumulate(c);
  cout << (sum % 5 || sum == 0 ? -1 : sum / 5) << endl;
}
