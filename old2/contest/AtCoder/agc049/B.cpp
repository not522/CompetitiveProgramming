#include "queue.hpp"
#include "string.hpp"

int main() {
  int64_t n(in), res = 0;
  String s(in), t(in);
  Queue<int64_t> que;
  for (int64_t i = 0; i < n; ++i) {
    if (s[i] == '1') {
      que.emplace(i);
    }
  }
  for (int64_t i = 0; i < n; ++i) {
    if (s[i] == '1') {
      que.pop();
    }
    if (s[i] == t[i]) {
      continue;
    }
    if (que.empty()) {
      cout << -1 << endl;
      return 0;
    }
    auto j = que.front();
    s[j] = '0';
    res += j - i;
  }
  cout << res << endl;
}
