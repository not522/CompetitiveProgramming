#include "template.hpp"

int main() {
  int a(in), b(in);
  cout << (a % b ? b - a % b : 0) << endl;
}
