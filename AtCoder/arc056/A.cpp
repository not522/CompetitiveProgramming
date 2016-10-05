#include "template.hpp"

int main() {
  int64_t a, b, k, l;
  cin >> a >> b >> k >> l;
  cout << min(k % l * a + k / l * b, k / l * b + b) << endl;
}
