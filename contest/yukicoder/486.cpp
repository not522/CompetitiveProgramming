#include "string.hpp"

int main() {
  String s(in);
  for (int i = 0; i + 2 < s.size(); ++i) {
    if (s.substr(i, 3) == "OOO") {
      cout << "East" << endl;
      return 0;
    }
    if (s.substr(i, 3) == "XXX") {
      cout << "West" << endl;
      return 0;
    }
  }
  cout << "NA" << endl;
}
