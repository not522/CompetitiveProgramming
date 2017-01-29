#include "binary_search.hpp"
#include "vector.hpp"

int main() {
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> a(n), b(n);
  cin >> a >> b;
  vector<pair<int, long long>> c(m);
  for (auto& i : c) cin >> i.first >> i.second;
  auto f = [&](int n){
    int ma = *min_element(a.begin(), a.begin() + n);
    int mb = *min_element(b.begin(), b.begin() + n);
    vector<long long> cost(m);
    for (int i = 0; i < m; ++i) cost[i] = (c[i].first == 1 ? ma : mb) * c[i].second;
    nth_element(cost, k);
    cost.resize(k);
    return accumulate(cost) <= s;
  };
  if (!f(n)) {
    cout << -1 << endl;
    return 0;
  }
  int d = binarySearch(f, n, 0);
  cout << d << endl;
  int ma = min_element(a.begin(), a.begin() + d) - a.begin();
  int mb = min_element(b.begin(), b.begin() + d) - b.begin();
  vector<pair<long long, int>> cost(m);
  for (int i = 0; i < m; ++i) cost[i] = make_pair((c[i].first == 1 ? a[ma] : b[mb]) * c[i].second, i);
  nth_element(cost, k);
  cost.resize(k);
  for (auto i : cost) cout << i.second + 1 << " " << (c[i.second].first == 1 ? ma : mb) + 1 << endl;
}
