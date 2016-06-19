#include "vector.hpp"

int main() {
  vector<int> a(2), b(2);
  cin >> a >> b;
  for (int i : a) {
    for (int j : b) {
      if (i == j) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
