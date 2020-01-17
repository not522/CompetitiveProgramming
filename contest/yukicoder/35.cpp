#include "string.hpp"

int main() {
  int n(in), ok = 0, miss = 0;
  for (int i = 0; i < n; ++i) {
    int t(in);
    String s(in);
    int k = min(s.size(), t * 12 / 1000);
    ok += k;
    miss += s.size() - k;
  }
  cout << ok << " " << miss << endl;
}
