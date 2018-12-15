#include "generator.hpp"
#include "constraints.hpp"

void gen_random(stringstream& ss, const map<string, boost::any>& args) {
  string func = any_cast<const char*>(args.at("func"));
  string t = any_cast<const char*>(args.at("t"));
  if (t == "int") {
    ss << func << " " << t << " " << rnd.next(numeric_limits<int>::min(), numeric_limits<int>::max()) << endl;
  } else {
    ss << func << " " << t << " " << rnd.next(MIN_N, MAX_N) << endl;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  map<string, vector<any>> args;
  args["func"] = vector<any>{"least_bit", "least_bit_fast", "most_bit", "count_bit"};
  args["t"] = vector<any>{"int", "int64_t"};
  generate_combination("10_random_", gen_random, args, 5);
}
