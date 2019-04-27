#include "template.hpp"

int main() {
  int64_t h, w, n, k;
  cin >> h >> w >> n >> k;
  cout << ((h * w - 1) % n == k - 1 ? "YES" : "NO") << endl;
}
