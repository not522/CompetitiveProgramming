#include "template.hpp"

int main() {
  vector<int> s(4);
  for (int& i : s) cin >> i;
  cout << 4 - set<int>(s.begin(), s.end()).size() << endl;
}
