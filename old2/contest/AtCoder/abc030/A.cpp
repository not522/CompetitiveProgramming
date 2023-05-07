#include "template.hpp"

int main() {
  int a(in), b(in), c(in), d(in);
  if (a * d < b * c) {
    cout << "TAKAHASHI" << endl;
  } else if (a * d > b * c) {
    cout << "AOKI" << endl;
  } else {
    cout << "DRAW" << endl;
  }
}
