#include "math/prime.hpp"
#include "game/grundy.hpp"

Prime prime;

class State {
private:
  int n;

public:
  State() {}

  State(int n) : n(n) {}

  State(Input in) : n(in) {}

  Vector<State> next() {
    auto factor = prime.primeFactor(n);
    Vector<State> res;
    for (auto i : factor) {
      res.emplace_back(n / i);
      if (n / i % i == 0) res.emplace_back(n / i / i);
    }
    return res;
  }

  bool operator<(const State& state) const {
    return n < state.n;
  }
};

int main() {
  setBoolName("Alice", "Bob");
  int n(in);
  Vector<State> m(n, in);
  Grundy<State> grundy;
  cout << grundy.solve(m) << endl;
}
