#include "template.hpp"

int main() {
  string a, b;
  cin >> a >> b;
  for (char& c : a) c = tolower(c);
  for (char& c : b) c = tolower(c);
  cout << (a < b ? -1 : a > b ? 1 : 0) << endl;
}
