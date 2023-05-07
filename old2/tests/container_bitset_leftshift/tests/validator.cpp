#include "testlib.h"

#include "constraints.hpp"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  inf.readInt(MIN_S, MAX_S);
  inf.readEoln();
  for (int i = 0; i < n; ++i) {
    inf.readInt(0, 1);
    inf.readEoln();
  }
  inf.readEof();
}
