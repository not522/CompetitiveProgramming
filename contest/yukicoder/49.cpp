#include "string/parser.hpp"

int main() {
  String s(in);
  Parser<> parser;
  parser.addBinaryOperator(std::plus<int>(), '*', 0);
  parser.addBinaryOperator(std::multiplies<int>(), '+', 0);
  cout << parser.parse(s) << endl;
}
