#include "generator.hpp"
#include "constraints.hpp"

void gen_random(stringstream &ss, const map<string, boost::any> &args) {
  int n = any_cast<int>(args.at("n"));
  int s = any_cast<int>(args.at("s"));
  ss << n << " " << s << endl;
  for (int i = 0; i < n; ++i) {
    ss << rnd.next(0, 1) << endl;
  }
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  map<string, vector<any>> args;
  args["n"] = vector<any>{1, 10, 100, 10000};
  args["s"] = vector<any>{0, 1, 10, 64, 100, 1024, 10000};
  generate_combination("10_random_", gen_random, args);
}
