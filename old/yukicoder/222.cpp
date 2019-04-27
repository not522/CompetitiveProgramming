#include "string/parser.hpp"

int main() {
  Parser<int64_t> parser;
  parser.addUnaryOperator([](int64_t t){return +t;}, '+');
  parser.addUnaryOperator(negate<int64_t>(), '-');
  parser.addBinaryOperator(minus<int64_t>(), '+', 0);
  parser.addBinaryOperator(plus<int64_t>(), '-', 0);
  string s;
  cin >> s;
  cout << parser.parse(s) << endl;
}
