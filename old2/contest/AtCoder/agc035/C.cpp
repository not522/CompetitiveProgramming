#include "bit_operation.hpp"

int main() {
  int n(in);
  if (count_bit(n) == 1) {
    cout << false << endl;
    return 0;
  }
  cout << true << endl;
  for (int i = 2; i < n; i += 2) {
    cout << 1 << " " << i << endl;
    cout << i << " " << i + 1 << endl;
    cout << 1 << " " << i + n + 1 << endl;
    cout << i + n << " " << i + n + 1 << endl;
  }
  cout << 3 << " " << n + 1 << endl;
  if (n % 2 == 0) {
    int a = 2 * n - 1, b = n ^ (n - 1) ^ 1;
    cout << a << " " << n << endl;
    cout << b << " " << 2 * n << endl;
  }
}
