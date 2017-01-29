#include "vector.hpp"

int main() {
  while (true) {
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    vector<int> x(n);
    cin >> x;
    sort(x);
    x.resize(k);
    cout << accumulate(x) << endl;
  }
}
