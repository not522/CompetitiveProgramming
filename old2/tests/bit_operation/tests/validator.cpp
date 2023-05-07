#include "testlib.h"

#include "constraints.hpp"

using namespace std;

int main() {
  registerValidation();
  string func = inf.readToken();
  inf.readSpace();
  string t = inf.readToken();
  inf.readSpace();
  int64_t n = inf.readLong(static_cast<long long>(MIN_N),
                           static_cast<long long>(MAX_N));
  inf.readEoln();
  inf.readEof();
  ensure(func == "least_bit" || func == "least_bit_fast" ||
         func == "most_bit" || func == "count_bit");
  ensure(t == "int" || t == "int64_t");
  if (func == "least_bit_fast") {
    ensure(n != 0);
  }
  if (t == "int") {
    ensure(n == int(n));
  }
}
