#include "vector.hpp"
#include "container/segment_tree.hpp"

class RangeMaximumQuery : public SegmentTree<int> {
protected:
  int function(int l, int r) {
    return max(l, r);
  }
  
public:
  RangeMaximumQuery(int n) : SegmentTree<int>(n, 0) {}
};

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> b(n);
  for (auto& i : b) cin >> i.first >> i.second;
  sort(b.begin(), b.end(), [](pair<int, int> i, pair<int, int> j){return i.first != j.first ? i.first < j.first : i.second > j.second;});
  RangeMaximumQuery rmq(1e5 + 1);
  for (auto i : b) {
    rmq.update(i.second, rmq.query(0, i.second) + 1);
  }
  cout << rmq.query(0, 1e5 + 1) << endl;
}
