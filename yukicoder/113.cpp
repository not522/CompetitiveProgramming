#include "template.hpp"

int main() {
  string s;
  cin >> s;
  int x = 0, y = 0;
  for (char c : s) {
    switch(c) {
    case 'N': ++y; break;
    case 'E': ++x; break;
    case 'W': --x; break;
    case 'S': --y; break;
    }
  }
  cout << sqrt(y * y + x * x) << endl;
}
