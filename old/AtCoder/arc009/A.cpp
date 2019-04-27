#include "template.hpp"

int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    sum += a * b;
  }
  cout << int(sum * 1.05) << endl;
}
