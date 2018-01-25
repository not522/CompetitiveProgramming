#include "vector.hpp"

int main() {
  vector<string> c(2);
  cin >> c;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (c[i][j] != c[1 - i][2 - j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
