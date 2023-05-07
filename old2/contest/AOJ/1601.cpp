#include "stack.hpp"
#include "string.hpp"

int main() {
  for (int n; n = in, n != 0;) {
    Vector<String> w(n, in);
    for (int i = 0;; ++i) {
      Stack<int> s({7, 7, 5, 7, 5});
      for (int j = i; j < n && !s.empty(); ++j) {
        int k = s.top() - w[j].size();
        if (k == 0) {
          continue;
        }
        s.emplace(k);
        if (k < 0) {
          break;
        }
      }
      if (s.empty()) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
}
