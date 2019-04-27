#include "game/min_max.hpp"

struct State {
  int turn, y, x;
  State(int turn, int y, int x) : turn(turn), y(y), x(x) {}
  bool operator<(const State& state) const {
    if (turn != state.turn) return turn < state.turn;
    if (y != state.y) return y < state.y;
    return x < state.x;
  }
};

class Game : public MinMax<int, State, true> {
private:
  int h, w;
  vector<string> s;
  map<State, int> mem;

  bool isTerminated(const State& state) const {
    return next(state).size() == 0u;
  }

  int eval(const State&) const {
    return -1;
  }

  bool used(const State& state) const {
    return mem.count(state) != 0;
  }

  int memo(const State& state) {
    return mem[state];
  }

  void use(const State& state, const int& score) {
    mem[state] = score;
  }

  vector<State> next(const State& state) const {
    vector<State> res;
    if (state.y != h - 1 && s[state.y + 1][state.x] != '#') {
      res.emplace_back(state.turn + 1, state.y + 1, state.x);
    }
    if (state.x != w - 1 && s[state.y][state.x + 1] != '#') {
      res.emplace_back(state.turn + 1, state.y, state.x + 1);
    }
    if (state.y != h - 1 && state.x != w - 1 && s[state.y + 1][state.x + 1] != '#') {
      res.emplace_back(state.turn + 1, state.y + 1, state.x + 1);
    }
    return res;
  }

public:
  Game(int h, int w, const vector<string>& s) : h(h), w(w), s(s) {}
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& i : s) cin >> i;
  Game game(h, w, s);
  cout << (game.solve(State(0, 0, 0)) == 1 ? "First" : "Second") << endl;
}
