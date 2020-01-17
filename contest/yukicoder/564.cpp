#include "vector.hpp"

int main() {
  int h(in), n(in), r = 1;
  Vector<int> v(n - 1, in);
  for (int i : v) {
    if (i > h) {
      ++r;
    }
  }
  cout << r;
  if (r % 10 == 1) {
    cout << "st" << endl;
  } else if (r % 10 == 2) {
    cout << "nd" << endl;
  } else if (r % 10 == 3) {
    cout << "rd" << endl;
  } else {
    cout << "th" << endl;
  }
}
