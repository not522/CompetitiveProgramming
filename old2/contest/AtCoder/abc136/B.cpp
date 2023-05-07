#include "string.hpp"

int main() {
  int n(in), r = 0;
  for (int i = 1; i <= n; ++i) {
    if (String(i).size() % 2 == 1) {
      ++r;
    }
  }
  cout << r << endl;
}
