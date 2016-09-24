#include "template.hpp"

int main() {
  int a, b;
  cin >> a >> b;
  if (0 < a) {
    cout << "Positive" << endl;
  } else if (b < 0) {
    cout << ((a - b) % 2 ? "Positive" : "Negative") << endl;
  } else {
    cout << "Zero" << endl;
  }
}
