#include "string/parser.hpp"

int main() {
  String s(in);
  Parser<int, LeadingZeros<int>> parser;
  parser.addBinaryOperator(std::plus<int>(), '+', 0);
  parser.addBinaryOperator(std::minus<int>(), '-', 0);
  int64_t res = -inf<int64_t>();
  for (int i = 0; i < s.size(); ++i) {
    try {
      chmax(res, parser.parse(s));
    } catch (const char *err) {
    }
    s.rotate(1);
  }
  cout << res << endl;
}
