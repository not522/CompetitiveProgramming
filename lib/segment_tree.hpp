#include "template.hpp"

template<typename T> class SegmentTree {
private:
  const T INF;
  int n;
  vector<T> d;
  
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return d[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return function(vl, vr);
  }

protected:
  virtual T function(T l, T r) = 0;
  
public:
  SegmentTree(int m) : INF(numeric_limits<T>::max()) {
    n = 1 << (32 - __builtin_clz(m - 1));
    d.resize(2 * n - 1, INF);
  }

  void update(int k, T a) {
    k += n - 1;
    d[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = function(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // [a,b)
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};
