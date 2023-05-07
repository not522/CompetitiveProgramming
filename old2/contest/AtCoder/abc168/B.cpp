#include "string.hpp"

int main() {
  int k(in);
  String s(in);
  if (s.size() <= k) {
    cout << s << endl;
  } else {
    cout << s.substr(0, k) << "..." << endl;
  }
}
