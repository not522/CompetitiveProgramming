#include "binary_search.hpp"
#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int64_t n, a, b;
  cin >> n >> a >> b;
  vector<int> h(n);
  cin >> h;
  auto f = [&](int64_t k){
             int64_t t = 0;
             for (int i : h) t += max(int64_t(0), ceil(i - b * k, a - b));
             return t <= k;
           };
  cout << binarySearch(f, 1e9, 0) << endl;
}
