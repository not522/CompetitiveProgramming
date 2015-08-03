#include "string/parser.hpp"

int main() {
  Parser<long long> parser;
  parser.addUnaryOperator([](long long t){return +t;}, '+');
  parser.addUnaryOperator(negate<long long>(), '-');
  parser.addBinaryOperator(minus<long long>(), '+', 0);
  parser.addBinaryOperator(plus<long long>(), '-', 0);
  string s;
  cin >> s;
  cout << parser.parse(s) << endl;
}
