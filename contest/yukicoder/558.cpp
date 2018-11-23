#include "template.hpp"

int main() {
  set_bool_name("YES", "NO");
  string s;
  cin >> s;
  cout << (s.find("575") != string::npos) << endl;
}
