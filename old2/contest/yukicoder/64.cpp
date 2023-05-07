#include "template.hpp"

int main() {
  int64_t f[3], n;
  f[0] = in;
  f[1] = in;
  n = in;
  f[2] = f[0] ^ f[1];
  cout << f[n % 3] << endl;
}
