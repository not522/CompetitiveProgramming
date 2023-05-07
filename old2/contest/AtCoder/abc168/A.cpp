#include "string.hpp"

int main() {
  String n(in);
  if (String("24579").contains(n.back())) {
    cout << "hon" << endl;
  } else if (String("0168").contains(n.back())) {
    cout << "pon" << endl;
  } else {
    cout << "bon" << endl;
  }
}
