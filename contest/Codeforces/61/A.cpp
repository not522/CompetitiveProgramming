#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  for (size_t i = 0; i < a.size(); ++i) cout << (a[i] ^ b[i]);
  cout << endl;
}
