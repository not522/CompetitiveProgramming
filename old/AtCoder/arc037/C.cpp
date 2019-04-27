#include "binary_search.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n), b(n);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  auto f = [&](int64_t x){
    return accumulate(a.begin(), a.end(), 0ll, [&](int64_t c, int64_t i){
        return c + upper_bound(b.begin(), b.end(), x / i) - b.begin();}) < k;
  };
  cout << binarySearch(f, 0, numeric_limits<int64_t>::max()) + 1 << endl;
}
