#include "template.hpp"

int main() {
  string o, e;
  cin >> o >> e;
  for (int i = 0; i < int(e.size()); ++i) cout << o[i] << e[i];
  if (o.size() > e.size()) cout << o.back();
  cout << endl;
}
