#include "template.hpp"

int main() {
  string sa, pa, xa, sb, pb, xb;
  cin >> sa >> pa >> xa >> sb >> pb >> xb;
  if (pa == pb) cout << -1 << endl;
  else if (pa.size() > pb.size() || (pa.size() == pb.size() && pa > pb)) cout << sa << endl;
  else cout << sb << endl;
}
