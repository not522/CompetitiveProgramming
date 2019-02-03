#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i].second >> s[i].first;
  rsort(s);
  int64_t res = 0;
  set<int> t;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  for (int i = 0; i < k; ++i) {
    res += s[i].first;
    if (t.count(s[i].second)) que.emplace(s[i]);
    else t.emplace(s[i].second);
  }
  res += square<int64_t>(t.size());
  auto r = res;
  for (int i = k; i < n && !que.empty(); ++i) {
    if (t.count(s[i].second)) continue;
    t.emplace(s[i].second);
    r -= que.top().first;
    que.pop();
    r += s[i].first + 2 * t.size() - 1;
    chmax(res, r);
  }
  cout << res << endl;
}
