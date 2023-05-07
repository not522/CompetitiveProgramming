#include "template.hpp"

int main() {
  int l(in), r(in);
  if (l / 2019 != r / 2019) {
    cout << 0 << endl;
  } else {
    int res = inf<int>();
    for (int64_t i = l; i <= r; ++i) {
      for (int64_t j = i + 1; j <= r; ++j) {
        chmin(res, i * j % 2019);
      }
    }
    cout << res << endl;
  }
}
