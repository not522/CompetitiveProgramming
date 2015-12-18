#include "string/to_string.hpp"

int main() {
  int n;
  while (cin >> n) {
    int t = 1;
    vector<int> res;
    for (; n; n /= 2, t *= 2) if (n % 2) res.emplace_back(t);
    cout << to_string(res) << endl;
  }
}
