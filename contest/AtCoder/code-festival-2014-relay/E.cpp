#include "vector.hpp"

int main() {
  int h, w, res = 0;
  cin >> h >> w;
  vector<string> b(h);
  cin >> b;
  for (auto& i : b) for (char j : i) if (isdigit(j)) res += j - '0';
  cout << res << endl;
}
