#include "vector.hpp"

int main() {
  vector<int> a(3);
  cin >> a;
  sort(a);
  cout << (a[0] + a[1] == a[2] ? "Yes" : "No") << endl;
}
