#include "template.hpp"

int main() {
  int n(in), k(in), x(in), y(in);
  cout << min(n, k) * x + max(n - k, 0) * y << endl;
}
