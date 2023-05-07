#include "string.hpp"

int main() {
  String sa(in), pa(in), xa(in), sb(in), pb(in), xb(in);
  if (pa == pb) {
    cout << -1 << endl;
  } else if (pa.size() > pb.size() || (pa.size() == pb.size() && pa > pb)) {
    cout << sa << endl;
  } else {
    cout << sb << endl;
  }
}
