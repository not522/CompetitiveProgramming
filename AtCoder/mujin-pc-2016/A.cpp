#include "template.hpp"

int main() {
  char c;
  cin >> c;
  if (string("OPKL").find(c) != string::npos) cout << "Right" << endl;
  else cout << "Left" << endl;
}
