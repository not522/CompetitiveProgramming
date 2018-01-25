#include "template.hpp"

int main() {
  string n;
  cin >> n;
  cout << ((n[0] == n[1] || n[2] == n[3]) && n[1] == n[2] ? "Yes" : "No") << endl;
}
