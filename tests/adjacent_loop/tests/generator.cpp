#include "generator.hpp"
#include "constraints.hpp"

void gen_random(stringstream &ss, const map<string, boost::any> &args) {
  int n = any_cast<int>(args.at("n"));
  int y = any_cast<int>(args.at("y"));
  int x = any_cast<int>(args.at("x"));
  ss << n << " " << y << " " << x << " " << 10 << " " << 10 << endl;
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  map<string, vector<any>> args;
  args["n"] = vector<any>{2, 4, 5, 8, 9};
  args["y"] = vector<any>{0, 5, 9};
  args["x"] = vector<any>{0, 5, 9};
  generate_combination("10_random_", gen_random, args);
}
