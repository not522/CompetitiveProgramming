#include "template.hpp"

int main() {
  array<int, 3> a;
  for (int& i : a) cin >> i;
  nth_element(a.begin(), a.begin() + 1, a.end());
  cout << a[1] << endl;
}
