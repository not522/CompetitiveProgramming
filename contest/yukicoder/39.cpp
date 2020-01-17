#include "string.hpp"

int main() {
  String n(in), res = n;
  for (int i = 0; i < n.size(); ++i) {
    for (int j = i + 1; j < n.size(); ++j) {
      String m = n;
      swap(m[i], m[j]);
      chmax(res, m);
    }
  }
  cout << res << endl;
}
