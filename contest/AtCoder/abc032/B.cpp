#include "template.hpp"

int main() {
  string s;
  int k;
  cin >> s >> k;
  set<string> st;
  for (int i = 0; i <= int(s.size()) - k; ++i) st.insert(s.substr(i, k));
  cout << st.size() << endl;
}
