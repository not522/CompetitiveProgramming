#include "game/grundy.hpp"
#include "vector.hpp"

class State {
private:
  int n;

public:
  State(int n) : n(n) {}

  Vector<Vector<State>> next() {
    Vector<Vector<State>> v;
    if (n >= 2) {
      v.emplace_back(Vector<State>({State(n / 2), State((n + 1) / 2)}));
    }
    if (n >= 3) {
      v.emplace_back(Vector<State>(
          {State(n / 3), State((n + 1) / 3), State((n + 2) / 3)}));
    }
    return v;
  }

  bool operator<(const State &state) const { return n < state.n; }
};

int main() {
  setBoolName("A", "B");
  int n(in);
  Grundy<State> grundy;
  cout << bool(grundy.solve(State(n))) << endl;
}
