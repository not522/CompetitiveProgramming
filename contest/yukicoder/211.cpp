#include "template.hpp"

int main() {
  int k(in), res = 0;
  for (int i : {2, 3, 5, 7, 11, 13}) {
    for (int j : {4, 6, 8, 9, 10, 12}) {
      if (i * j == k) {
        ++res;
      }
    }
  }
  cout << res / 36. << endl;
}
