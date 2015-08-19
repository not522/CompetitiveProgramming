#include "template.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int& i : a) cin >> i;
  sort(a.begin(), a.end());
  deque<int> b(a.begin(), a.end()), c = b, d = b;
  int dry = 0, wet = 0, moist = 0;
  while (b.size() > 1u) {
    if (b.front() + b.back() < 0) {
      ++dry;
      b.pop_front();
    }
    b.pop_back();
  }
  while (c.size() > 1u) {
    if (c.front() + c.back() > 0) {
      ++wet;
      c.pop_back();
    }
    c.pop_front();
  }
  while (d.size() > 1u) {
    if (d.front() + d.back() == 0) {
      ++moist;
      d.pop_front();
      d.pop_back();
    } else if (d.front() + d.back() < 0) {
      d.pop_front();
    } else {
      d.pop_back();
    }
  }
  cout << dry << " " << wet << " " << moist << endl;
}
