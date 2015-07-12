#include "game/alpha_beta.hpp"

typedef array<array<int, 3>, 3> Board;

struct State {
  int turn;
  Board board;
  State() : turn(0) {
    for (auto& i : board) {
      for (auto& j : i) j = -1;
    }
  }
};

class Game : public AlphaBeta<int, State> {
private:
  const array<array<int, 3>, 2> b;
  const array<array<int, 2>, 3> c;
  
protected:
  bool isTerminated(const State& state) const {
    return state.turn == 9;
  }
  
  int eval(const State& state) const {
    int res = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (state.board[i][j] == state.board[i + 1][j]) res += b[i][j];
        else res -= b[i][j];
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (state.board[i][j] == state.board[i][j + 1]) res += c[i][j];
        else res -= c[i][j];
      }
    }
    return state.turn % 2 ? -res : res;
  }

  vector<State> next(const State& state) const {
    vector<State> res;
    State next = state;
    next.turn = state.turn + 1;
    for (auto& i : next.board) {
      for (auto& j : i) {
        if (j != -1) continue;
        j = state.turn % 2;
        res.emplace_back(next);
        j = -1;
      }
    }
    return res;
  }

public:
  Game(const array<array<int, 3>, 2>& b, const array<array<int, 2>, 3>& c) : b(b), c(c){}
};

int main() {
  array<array<int, 3>, 2> b;
  array<array<int, 2>, 3> c;
  int sum = 0;
  for (auto& i : b) {
    for (auto& j : i) {
      cin >> j;
      sum += j;
    }
  }
  for (auto& i : c) {
    for (auto& j : i) {
      cin >> j;
      sum += j;
    }
  }
  Game game(b, c);
  int res = game.solve(State(), 9);
  cout << (sum + res) / 2 << endl;
  cout << (sum - res) / 2 << endl;
}
