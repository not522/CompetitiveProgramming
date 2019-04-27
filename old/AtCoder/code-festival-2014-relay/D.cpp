#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> b(n);
  cin >> b;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == 'X') c1 += i;
      if (b[i][j] == 'Y') c2 += n - i - 1;
    }
  }
  cout << (c1 == c2 ? "Impossible" : c1 > c2 ? "X" : "Y") << endl;
}
