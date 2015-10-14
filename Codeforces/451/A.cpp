#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  cout << (min(n, m) % 2 ? "Akshat" : "Malvika") << endl;
}
