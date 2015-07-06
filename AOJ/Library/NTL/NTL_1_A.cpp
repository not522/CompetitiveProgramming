#include "math/prime.hpp"

int main() {
  int n;
  cin >> n;
  Prime prime(1000000);
  cout << n << ":";
  for (int f : prime.factor(n)) cout << " " << f;
  cout << endl;
}
