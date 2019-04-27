#include "container/segment_tree.hpp"
#include "vector.hpp"

class RangeMaximumQuery : public SegmentTree<int> {
protected:
  int function(int l, int r) { return max(l, r); }

public:
  RangeMaximumQuery(int n) : SegmentTree<int>(n, 0) {}
};

int main() {
  int n(in);
  Vector<Tuple<int, int>> b(n, in);
  b.sort([](const Tuple<int, int> &i, const Tuple<int, int> &j) {
    return i.get<0>() != j.get<0>() ? i.get<0>() < j.get<0>()
                                    : i.get<1>() > j.get<1>();
  });
  RangeMaximumQuery rmq(1e5 + 1);
  for (auto i : b) {
    rmq.update(i.get<1>(), rmq.query(0, i.get<1>()) + 1);
  }
  cout << rmq.query(0, 1e5 + 1) << endl;
}
