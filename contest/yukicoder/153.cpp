#include "game/grundy.hpp"

class State {
private:
  int n;

public:
  State (int n) : n(n) {}

  vector<vector<State>> next() {
    vector<vector<State>> v;
    if (n >= 2) v.emplace_back(vector<State>({State(n / 2), State((n + 1) / 2)}));
    if (n >= 3) v.emplace_back(vector<State>({State(n / 3), State((n + 1) / 3), State((n + 2) / 3)}));
    return v;
  }

  bool operator<(const State& state) const {
    return n < state.n;
  }
};

int main() {
  int n;
  cin >> n;
  Grundy<State> grundy;
  cout << (grundy.solve(State(n)) ? "A" : "B") << endl;
}
