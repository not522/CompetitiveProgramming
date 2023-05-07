#include "template.hpp"

int main() {
  int n(in);
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (i * j == n) {
        cout << true << endl;
        return 0;
      }
    }
  }
  cout << false << endl;
}
