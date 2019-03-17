#include "string.hpp"

int main() {
  for (int a, b; cin >> a >> b;) {
    cout << String(a + b).size() << endl;
  }
}
