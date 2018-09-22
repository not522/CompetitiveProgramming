#include "vector.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  cin >> a;
  cout << string(w + 2, '#') << endl;
  for (int i = 0; i < h; ++i) cout << '#' << a[i] << '#' << endl;
  cout << string(w + 2, '#') << endl;
}
