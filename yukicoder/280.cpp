#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> z(n);
  for (int& i : z) cin >> i;
  cout << z.back() << "/" << z[0] << endl;
}
