#include "template.hpp"

int main() {
  char C, c;
  cin >> C >> c;
  cout << (tolower(C) == c ? "Yes" : "No") << endl;
}
