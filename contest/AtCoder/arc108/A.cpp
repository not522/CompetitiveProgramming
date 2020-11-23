#include "template.hpp"

int main() {
  int64_t s(in), p(in);
  for (int64_t i = 1; i * i <= p; ++i) {
    if (p % i) {
      continue;
    }
    auto j = p / i;
    if (i + j == s) {
      cout << true << endl;
      return 0;
    }
  }
  cout << false << endl;
}
