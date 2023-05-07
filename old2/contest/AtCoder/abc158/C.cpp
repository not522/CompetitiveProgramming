#include "template.hpp"

int main() {
  int a(in), b(in);
  for (int i = 0; i <= 10 * b + 10; ++i) {
    if (int(i * 0.08) == a && int(i * 0.1) == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
