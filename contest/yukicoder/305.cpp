#include "string.hpp"

int get(int64_t i) {
  cout << std::setw(10) << std::setfill('0') << i << endl;
  int x(in);
  String s(in);
  if (s == "unlocked") {
    exit(0);
  }
  return x;
}

int main() {
  int64_t res = 0;
  String s;
  for (int64_t i = 1e9; i; i /= 10) {
    Vector<int> v;
    for (int j = 0; j < 10; ++j) {
      v.emplace_back(get(i * j));
    }
    res = res * 10 + v.argmax();
  }
  get(res);
}
