#include "binary_search.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> h(n), s(n);
  for (int i = 0; i < n; ++i) cin >> h[i] >> s[i];
  auto f = [&](int64_t m){
    vector<int64_t> v;
    for (int i = 0; i < n; ++i) v.emplace_back((m - h[i]) / s[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
      if (v[i] < i || h[i] > m) return false;
    }
    return true;
  };
  cout << binarySearch(f, 0, numeric_limits<int64_t>::max()) << endl;
}
