#include "vector.hpp"
#include "container/segment_tree.hpp"

class Frogs : public SegmentTree<int64_t> {
private:
  int64_t function(int64_t l, int64_t r) {return max(l, r);}

public:
  Frogs(int n) : SegmentTree<int64_t>(n) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  Frogs frogs(n);
  vector<tuple<int, int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(a[i]) >> get<1>(a[i]);
    get<2>(a[i]) = i;
  }
  sort(a);
  for (int i = 0; i < n; ++i) frogs.update(i, get<0>(a[i]) + get<1>(a[i]));
  multiset<pair<int, int>> s;
  vector<int> c(n);
  for (int i = 0; i < m; ++i) {
    int p, b;
    cin >> p >> b;
    int k = frogs.lower_bound(p);
    if (k >= n || get<0>(a[k]) > p) {
      s.insert(make_pair(p, b));
    } else {
      frogs.update(k, frogs.getValue(k) + b);
      ++c[k];
      while (!s.empty()) {
        auto j = s.lower_bound(make_pair(get<0>(a[k]), 0));
        if (j == s.end() || j->first > frogs.getValue(k)) break;
        frogs.update(k, frogs.getValue(k) + j->second);
        ++c[k];
        s.erase(j);
      }
    }
  }
  vector<pair<int, int64_t>> res(n);
  for (int i = 0; i < n; ++i) res[get<2>(a[i])] = make_pair(c[i], frogs.getValue(i) - get<0>(a[i]));
  for (int i = 0; i < n; ++i) cout << res[i].first << " " << res[i].second << endl;
}
