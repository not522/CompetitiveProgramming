#include "template.hpp"

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  cin >> c;
  vector<int> a(3), b(3);
  for (int i = 0; i < 3; ++i) b[i] = c[i][0];
  for (int i = 1; i < 3; ++i) a[i] = c[0][i] - b[0];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[j] + b[i] != c[i][j]) {
        cout << false << endl;
        return 0;
      }
    }
  }
  cout << true << endl;
}
