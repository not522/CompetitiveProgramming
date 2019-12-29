#include "string.hpp"
#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  Vector<String> c(2, in);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (c[i][j] != c[1 - i][2 - j]) {
        cout << false << endl;
        return 0;
      }
    }
  }
  cout << true << endl;
}
