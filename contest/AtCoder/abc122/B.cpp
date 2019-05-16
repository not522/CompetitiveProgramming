#include "string.hpp"

int main() {
  String s(in);
  int res = 0, k = 0;
  for (char c : s) {
    if (String("ACGT").contains(c)) {
      ++k;
      chmax(res, k);
    } else {
      k = 0;
    }
  }
  cout << res << endl;
}
