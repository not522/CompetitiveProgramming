#include "string.hpp"

int main() {
  int n(in);
  (void)n;
  String s(in), t(in);
  cout << s.inner_product(t, 0, std::plus<int>(), std::not_equal_to<int>())
       << endl;
}
