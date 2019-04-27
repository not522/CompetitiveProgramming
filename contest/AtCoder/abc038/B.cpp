#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  Vector<int> a(2, in), b(2, in);
  for (int i : a) {
    for (int j : b) {
      if (i == j) {
        cout << true << endl;
        return 0;
      }
    }
  }
  cout << false << endl;
}
