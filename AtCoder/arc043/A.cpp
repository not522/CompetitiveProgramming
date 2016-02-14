#include "vector.hpp"

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  vector<long long> s(n);
  cin >> s;
  long long sum = accumulate(s), mn = min(s), mx = max(s);
  if (mn == mx && s[0] != a) {
    cout << -1 << endl;
    return 0;
  }
  double p = (double)b / (mx - mn);
  cout << p << " " << a - sum * p / n << endl;
}
