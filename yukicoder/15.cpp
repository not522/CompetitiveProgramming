#include "container/power_set.hpp"
#include "string/to_string.hpp"

vector<pair<int, vector<int>>> solve(const vector<int>& p) {
  vector<pair<int, vector<int>>> res;
  for (auto t : PowerSet(p.size())) {
    int sum = 0;
    vector<int> v;
    for (auto i : t) {
      sum += p[int(i)];
      v.emplace_back(i);
    }
    res.emplace_back(make_pair(sum, v));
  }
  return res;
}

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> p(n / 2), q(n - n / 2);
  for (int& i : p) cin >> i;
  for (int& i : q) cin >> i;
  unordered_map<int, vector<vector<int>>> a;
  for (const auto& i : solve(p)) a[i.first].emplace_back(i.second);
  vector<vector<int>> res;
  for (const auto& i : solve(q)) {
    for (const auto& u : a[s - i.first]) {
      vector<int> vv;
      for (int j : u) vv.emplace_back(j + 1);
      for (int j : i.second) vv.emplace_back(j + n / 2 + 1);
      res.emplace_back(vv);
    }
  }
  sort(res.begin(), res.end());
  for (const auto& i : res) cout << to_string(i) << endl;
}
