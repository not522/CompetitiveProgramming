#include "template.hpp"

int main() {
  long long h, w, n, k;
  cin >> h >> w >> n >> k;
  cout << ((h * w - 1) % n == k - 1 ? "YES" : "NO") << endl;
}
