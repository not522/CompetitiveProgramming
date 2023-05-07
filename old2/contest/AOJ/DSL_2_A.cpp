#include "container/rmq.hpp"

int main() {
  int n(in), q(in);
  RMQ<int> rmq(n);
  for (int i = 0; i < q; ++i) {
    int com(in), x(in), y(in);
    if (com == 0) {
      rmq.update(x, y);
    } else {
      cout << rmq.query(x, y + 1) << endl;
    }
  }
}
