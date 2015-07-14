#include "template.hpp"

int main() {
  int k, n, f;
  cin >> k >> n >> f;
  int sum = 0;
  for (int i = 0; i < f; ++i) {
    int a;
    cin >> a;
    sum += a;
  }
  cout << (k * n < sum ? -1 : k * n - sum) << endl;
}
