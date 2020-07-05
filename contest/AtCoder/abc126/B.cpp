#include "string.hpp"

int main() {
  String s(in);
  bool a = (1 <= int(s.substr(0, 2)) && int(s.substr(0, 2)) <= 12);
  bool b = (1 <= int(s.substr(2)) && int(s.substr(2)) <= 12);
  if (a) {
    if (b) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    if (b) {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    }
  }
}
