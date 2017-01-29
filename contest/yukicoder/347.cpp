#include "vector.hpp"

int main() {
  int n, b;
  cin >> n >> b;
  vector<double> a(n);
  cin >> a;
  double r1 = 0, r2 = 0;
  for (auto i : a) {
    r1 += i * pow(b, i - 1);
    r2 += i != -1 ? pow(b, i + 1) / (i + 1) : log(b);
  }
  cout << r1 << endl << r2 << endl;
}
