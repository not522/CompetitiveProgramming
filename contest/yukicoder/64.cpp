#include "template.hpp"

int main() {
  long long f[3], n;
  cin >> f[0] >> f[1] >> n;
  f[2] = f[0] ^ f[1];
  cout << f[n % 3] << endl;
}
