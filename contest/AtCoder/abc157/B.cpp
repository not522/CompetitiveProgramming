#include "vector.hpp"

int main() {
  auto a = Vector<int>::makeVector(in, 3, 3);
  int n(in);
  Vector<int> b(n, in);
  for (auto &i : a) {
    for (int &j : i) {
      for (int k : b) {
        if (j == k) {
          j = 0;
        }
      }
    }
  }
  for (int i = 0; i < 3; ++i) {
    if (a[i].accumulate() == 0) {
      cout << true << endl;
      return 0;
    }
    if (a[0][i] + a[1][i] + a[2][i] == 0) {
      cout << true << endl;
      return 0;
    }
  }
  if (a[0][0] + a[1][1] + a[2][2] == 0) {
    cout << true << endl;
    return 0;
  }
  if (a[0][2] + a[1][1] + a[2][0] == 0) {
    cout << true << endl;
    return 0;
  }
  cout << false << endl;
}
