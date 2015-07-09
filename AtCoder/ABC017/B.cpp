#include "template.hpp"

int main() {
  string x;
  cin >> x;
  while (!x.empty()) {
    if (x.size() >= 2u && x.substr(x.size() - 2) == "ch") x = x.substr(0, x.size() - 2);
    else if (x.back() == 'o') x.pop_back();
    else if (x.back() == 'k') x.pop_back();
    else if (x.back() == 'u') x.pop_back();
    else break;
  }
  cout << (x.empty() ? "YES" : "NO") << endl;
}
