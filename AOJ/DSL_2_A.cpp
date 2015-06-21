#include "rmq.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  RMQ<int> rmq(n);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) rmq.update(x, y);
    else cout << rmq.query(x, y + 1) << endl;
  }
}
