#include "template.hpp"

int main() {
  string s;
  cin >> s;
  for (char c : s) {
    c = tolower(c);
    if (string("aoyeui").find(c) == string::npos) cout << "." << c;
  }
  cout << endl;
}
