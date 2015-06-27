#include "dp/divide_and_conquer.hpp"

class Bullion : public DivideAndConquer<int, int, int, int, int> {
private:
  vector<pair<int, int>> c;
  map<array<int, 4>, int> m;
  
protected:
  bool used(int l, int b, int r, int t) {
    return m.count({l, b, r, t});
  }
  
  int memo(int l, int b, int r, int t) {
    return m[{l, b, r, t}];
  }

  int value(int l, int b, int r, int t) {
    int res = 0;
    for (const auto& k : c) {
      if (k.first < l || r < k.first || k.second < b || t < k.second) continue;
      int a = (r - l) + (t - b) + 1;
      a += solve(l, b, k.first - 1, k.second - 1);
      a += solve(k.first + 1, b, r, k.second - 1);
      a += solve(l, k.second + 1, k.first - 1, t);
      a += solve(k.first + 1, k.second + 1, r, t);
      res = max(res, a);
    }
    return res;
  }

  void push(int v, int l, int b, int r, int t) {
    m[{l, b, r, t}] = v;
  }

public:
  Bullion(int w, int h, const vector<pair<int, int>>& c) : c(c) {}
};

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<pair<int, int>> c(n);
  for (auto& i : c) cin >> i.first >> i.second;
  Bullion bullion(w, h, c);
  cout << bullion.solve(1, 1, w, h) << endl;
}
