#include "segment_tree.hpp"

template<typename T> class RSQ : public SegmentTree<T> {
protected:
  T function(T l, T r) {
    return l + r;
  }
  
public:
  RSQ(int n) : SegmentTree<T>(n, 0) {}
};

int main() {
  int n, q;
  cin >> n >> q;
  RSQ<int> rsq(n + 1);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) rsq.update(x, rsq.getValue(x) + y);
    else cout << rsq.query(x, y + 1) << endl;
  }
}
