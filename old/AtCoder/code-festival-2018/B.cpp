#include "template.hpp"

int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 0; i <= x / 3; ++i) {
    int j = x - i * 3;
    if (i + j * 3 == y) {
      cout << true << endl;
      return 0;
    }
  }
  cout << false << endl;
}
