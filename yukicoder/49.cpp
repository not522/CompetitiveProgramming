#include "string/parser.hpp"

int main() {
  string s;
  cin >> s;
  Parser<> parser;
  parser.addBinaryOperator(plus<int>(), '*', 0);
  parser.addBinaryOperator(multiplies<int>(), '+', 0);
  cout << parser.parse(s) << endl;
}
