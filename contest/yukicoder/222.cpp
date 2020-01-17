#include "string/parser.hpp"

int main() {
  Parser<int64_t> parser;
  parser.addUnaryOperator([](int64_t t) { return +t; }, '+');
  parser.addUnaryOperator(std::negate<int64_t>(), '-');
  parser.addBinaryOperator(std::minus<int64_t>(), '+', 0);
  parser.addBinaryOperator(std::plus<int64_t>(), '-', 0);
  String s(in);
  cout << parser.parse(s) << endl;
}
