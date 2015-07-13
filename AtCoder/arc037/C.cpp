#include "binary_search.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n), b(n);
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  auto f = [&](long long x){
    return accumulate(a.begin(), a.end(), 0ll, [&](long long c, long long i){
        return c + upper_bound(b.begin(), b.end(), x / i) - b.begin();}) < k;
  };
  cout << binarySearch(f, 0, numeric_limits<long long>::max()) + 1 << endl;
}
