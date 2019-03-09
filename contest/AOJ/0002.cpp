#include "string.hpp"

int main() {
  int a, b;
  while (cin >> a >> b) {
    cout << String(a + b).size() << endl;
  }
}
