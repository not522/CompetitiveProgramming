#include "map.hpp"
#include "string.hpp"

int main() {
  int mx1 = 0, mx2 = 0;
  String amx1, amx2;
  Map<String, int> m;
  for (String s; s = in, !in.eof;) {
    ++m[s];
    if (chmax(mx1, m[s])) {
      amx1 = s;
    }
    if (chmax(mx2, int(s.size()))) {
      amx2 = s;
    }
  }
  cout << amx1 << " " << amx2 << endl;
}
