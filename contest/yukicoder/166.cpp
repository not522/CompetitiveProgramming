#include "template.hpp"

int main() {
  setBoolName("YES", "NO");
  int64_t h(in), w(in), n(in), k(in);
  cout << ((h * w - 1) % n == k - 1) << endl;
}
