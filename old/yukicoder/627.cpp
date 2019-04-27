#include "template.hpp"

int main() {
  set_bool_name("T", "F");
  int t;
  cin >> t;
  vector<int> x(t);
  cin >> x;
  if (abs(x[0]) != 1) {
    cout << false << endl;
    return 0;
  }
  for (int i = 0; i < t - 1; ++i) {
    if (abs(x[i] - x[i + 1]) != 1) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
