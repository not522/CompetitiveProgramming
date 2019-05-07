#include "testlib.h"

#include "constraints.hpp"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt();
  inf.readSpace();
  int y = inf.readInt(MIN_Y, MAX_Y);
  inf.readSpace();
  int x = inf.readInt(MIN_X, MAX_X);
  inf.readSpace();
  int h = inf.readInt(MIN_H, MAX_H);
  inf.readSpace();
  int w = inf.readInt(MIN_W, MAX_W);
  inf.readEoln();
  inf.readEof();
  ensure(n == 2 || n == 4 || n == 5 || n == 8 || n == 9);
  ensure(0 <= y && y < h);
  ensure(0 <= x && x < w);
}
