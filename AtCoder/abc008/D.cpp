#include "dp/memoized_recursion.hpp"

class Bullion : public MemoizedRecursion<int, int, int, int, int> {
private:
  vector<pair<int, int>> c;
  
  int eval(int l, int b, int r, int t) {
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

public:
  Bullion(const vector<pair<int, int>>& c) : c(c) {}
};

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<pair<int, int>> c(n);
  for (auto& i : c) cin >> i.first >> i.second;
  Bullion bullion(c);
  cout << bullion.solve(1, 1, w, h) << endl;
}
