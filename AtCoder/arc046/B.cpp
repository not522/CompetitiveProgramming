#include "template.hpp"

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n <= a) cout << "Takahashi" << endl;
  else if (a > b) cout << "Takahashi" << endl;
  else if (a < b) cout << "Aoki" << endl;
  else if (n % (a + 1)) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;
}
