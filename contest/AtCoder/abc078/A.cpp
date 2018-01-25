#include "template.hpp"

int main() {
  char x, y;
  cin >> x >> y;
  cout << (x < y ? '<' : x == y ? '=' : '>') << endl;
}
