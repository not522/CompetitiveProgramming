#include "testlib.h"

#include "constraints.hpp"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(MIN_N, MAX_N);
  inf.readEoln();
  for (int i = 0; i < n; ++i) {
    inf.readInt(MIN_A, MAX_A);
    inf.readEoln();
  }
  inf.readEof();
}
