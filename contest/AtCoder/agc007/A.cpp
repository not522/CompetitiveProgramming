#include "adjacent_loop.hpp"
#include "vector.hpp"

int main() {
  int h, w, i = 0, j = 0;
  cin >> h >> w;
  vector<string> a(h);
  cin >> a;
  a[0][0] = '.';
  while (i != h - 1 || j != w - 1) {
    bool update = false;
    for (const auto& k : AdjacentLoop<2>(i, j, h, w)) {
      if (a[k.first][k.second] == '.') continue;
      i = k.first;
      j = k.second;
      a[i][j] = '.';
      update = true;
      break;
    }
    if (update) continue;
    cout << "Impossible" << endl;
    return 0;
  }
  for (const auto& i : a) {
    if (i.find('#') == string::npos) continue;
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
}
