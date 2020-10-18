#include "priority_queue.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n, in), b(n, in);
  auto c = a - b;
  auto b_sum = b.accumulate();
  PriorityQueue<int64_t> que1, que2;
  for (int i = 0; i < n / 2; ++i) {
    que1.emplace(c[2 * i]);
    que2.emplace(c[2 * i + 1]);
  }
  auto res = b_sum, r = b_sum;
  for (int i = 0; i < n / 2; ++i) {
    auto t1 = que1.top();
    auto t2 = que2.top();
    r += t1 + t2;
    chmax(res, r);
  }
  cout << res << endl;
}
