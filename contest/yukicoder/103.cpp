#include "math/prime.hpp"
#include "game/grundy.hpp"

Prime prime;

class State {
private:
  int n;

public:
  State() {}

  State(int n) : n(n) {}

  vector<State> next() {
    auto factor = prime.primeFactor(n);
    vector<State> res;
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
  int n;
  cin >> n;
  vector<State> m(n);
  for (auto& i : m) {
    int j;
    cin >> j;
    i = j;
  }
  Grundy<State> grundy;
  cout << (grundy.solve(m) ? "Alice" : "Bob") << endl;
}
