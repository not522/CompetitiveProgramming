#include "generator.hpp"
#include "constraints.hpp"

void gen_random(stringstream &ss) {
  int n = rnd.next(MIN_N, MAX_N);
  ss << n << endl;
  for (int i = 0; i < n; ++i) {
    ss << rnd.next(MIN_A, MAX_A) << endl;
  }
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  generate("10_random_", gen_random);
}
