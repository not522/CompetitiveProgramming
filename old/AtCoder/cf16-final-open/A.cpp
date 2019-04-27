#include "vector.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<string>> s(h, vector<string>(w));
  cin >> s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == "snuke") cout << char(j + 'A') << i + 1 << endl;
    }
  }
}
