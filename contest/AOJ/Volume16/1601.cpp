#include "vector.hpp"

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<string> w(n);
    cin >> w;
    for (int i = 0; ; ++i) {
      stack<int> s({7, 7, 5, 7, 5});
      for (int j = i; j < n && !s.empty(); ++j) {
        int k = s.top();
        s.pop();
        k -= w[j].size();
        if (k == 0) continue;
        s.emplace(k);
        if (k < 0) break;
      }
      if (s.empty()) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
