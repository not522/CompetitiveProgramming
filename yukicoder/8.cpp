#include "template.hpp"

int main() {
  int p;
  cin >> p;
  for (int i = 0; i < p; ++i) {
    int n, k;
    cin >> n >> k;
    cout << (n % (k + 1) != 1 ? "Win" : "Lose") << endl;
  }
}
