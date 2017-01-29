#include "template.hpp"

int main() {
  long long n;
  cin >> n;
  vector<long long> res;
  for (long long m = n; n - m < 200 && m > 0; --m) {
    string s = to_string(m);
    auto f = [](int n, char c){return n + c - '0';};
    if (m + accumulate(s.begin(), s.end(), 0, f) == n) res.emplace_back(m);
  }
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  for (const auto& i : res) cout << i << endl;
}
