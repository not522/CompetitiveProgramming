#include "string/parser.hpp"

int main() {
  string s;
  cin >> s;
  Parser<> parser;
  parser.addOperator(plus<int>(), '*', 0);
  parser.addOperator(multiplies<int>(), '+', 0);
  cout << parser.parse(s) << endl;
}
