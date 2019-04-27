#include "vector.hpp"
#include "string/join.hpp"

vector<int> p;

int cnt(const vector<pair<int, int>>& d, int m) {
  int res = 0, k = 0;
  for (int i = 0; k < m && i < int(d.size()); ++i) {
    bool ok = true;
    for (int v = d[i].second; v != -1; v = p[v]) {
      if (d[i].first == -1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res += d[i].first;
      ++k;
    }
  }
  if (k < m) return numeric_limits<int>::max();
  return res;
}

int count_min(vector<int> d, int m) {
  vector<pair<int, int>> dd;
  for (int i = 0; i < int(d.size()); ++i) dd.emplace_back(d[i], i);
  sort(dd);
  return cnt(dd, m);
}

int count_max(vector<int> d, int m) {
  vector<pair<int, int>> dd;
  for (int i = 0; i < int(d.size()); ++i) dd.emplace_back(d[i], i);
  rsort(dd);
  return cnt(dd, m);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  p.resize(n);
  vector<int> d(n, -1);
  cin >> p;
  for (int i = 0; i < n; ++i) {
    --p[i];
    if (p[i] == -1) d[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (d[j] == -1 && d[p[j]] != -1) d[j] = d[p[j]] + 1;
    }
  }
  if (count_min(d, m) > k || count_max(d, m) < k) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> v;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      bool ok = true;
      for (int v = i; v != -1; v = p[v]) {
        if (d[v] == -1) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      int dd = d[i];
      k -= dd;
      d[i] = -1;
      if (count_min(d, m - j - 1) <= k && k <= count_max(d, m - j - 1)) {
        v.emplace_back(i + 1);
        break;
      }
      k += dd;
      d[i] = dd;
    }
  }
  cout << join(v) << endl;
}
