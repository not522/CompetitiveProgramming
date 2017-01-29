#include "big_decimal.hpp"

int main() {
  string ope;
  while (cin >> ope) {
    BigDecimal<> a, b, res;
    if (ope == "add" || ope == "sub" || ope == "mul" || ope == "div" || ope == "pow" || ope == "atan2") {
      cin >> a >> b;
      if (ope == "add") res = a + b;
      if (ope == "sub") res = a - b;
      if (ope == "mul") res = a * b;
      if (ope == "div") res = a / b;
      if (ope == "pow") res = pow(a, b);
      if (ope == "atan2") res = atan2(a, b);
    } else {
      cin >> a;
      if (ope == "exp") res = exp(a);
      if (ope == "ln") res = log(a);
      if (ope == "sqrt") res = sqrt(a);
      if (ope == "asin") res = asin(a);
      if (ope == "acos") res = acos(a);
      if (ope == "atan") res = atan(a);
      if (ope == "sin") res = sin(a);
      if (ope == "cos") res = cos(a);
      if (ope == "tan") res = tan(a);
    }
    int p;
    cin >> p;
    cout << setprecision(p) << res << endl;
  }
}
