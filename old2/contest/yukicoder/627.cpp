#include "vector.hpp"

int main() {
  setBoolName("T", "F");
  int t(in);
  Vector<int> x(t, in);
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
