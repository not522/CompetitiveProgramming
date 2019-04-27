#include "template.hpp"

int main() {
  string n;
  cin >> n;
  cout << (n[0] == '9' || n[1] == '9' ? "Yes" : "No") << endl;
}
