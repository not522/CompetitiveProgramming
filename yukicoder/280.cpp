#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> z(n);
  cin >> z;
  cout << z.back() << "/" << z[0] << endl;
}
