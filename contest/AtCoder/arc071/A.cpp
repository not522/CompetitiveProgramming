#include "count.hpp"

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  vector<int> cnt(26, numeric_limits<int>::max());
  for (auto& i : s) {
    auto c = count(i);
    for (int i = 0; i < 26; ++i) chmin(cnt[i], c[i + 'a']);
  }
  for (int i = 0; i < 26; ++i) cout << string(cnt[i], i + 'a');
  cout << endl;
}
