#include "template.hpp"

int main() {
  string s, t = "CODEFESTIVAL2016";
  cin >> s;
  cout << inner_product(s.begin(), s.end(), t.begin(), 16, minus<int>(), equal_to<char>()) << endl;
}
