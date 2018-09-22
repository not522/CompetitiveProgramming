#include "bit_operation.hpp"
#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int& i : a) i = least_bit(i);
  cout << min(a) << endl;
}
