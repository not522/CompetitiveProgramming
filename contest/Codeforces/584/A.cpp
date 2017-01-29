#include "template.hpp"

int main() {
  int n, t;
  cin >> n >> t;
  if (n >= (int)to_string(t).size()) {
    cout << t << string(n - to_string(t).size(), '0') << endl;
  } else {
    cout << -1 << endl;
  }
}
