#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int64_t n;
  cin >> n;
  int res = accumulate(to_string(n), 0, [](int a, char b){return a + b - '0';});
  for (int64_t i = 1; i * 10 <= n; i *= 10) {
    n -= (n / i % 10 + 1) % 10 * i;
    chmax(res, accumulate(to_string(n), 0, [](int a, char b){return a + b - '0';}));
  }
  cout << res << endl;
}
