#include "template.hpp"

int main() {
  string s;
  cin >> s;
  if (s.substr(s.size() - 2) == "ai") {
    cout << s.substr(0, s.size() - 2) << "AI" << endl;
  } else {
    cout << s << "-AI" << endl;
  }
}
