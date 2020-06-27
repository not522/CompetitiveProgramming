#include "template.hpp"

int main() {
  int n(in);
  for (int i = 1; i <= 50000; ++i) {
    if (int(i * 1.08) == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}
