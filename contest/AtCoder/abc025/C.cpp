#include "game/alpha_beta.hpp"

struct State {
  int turn;
  Vector<Vector<int>> board;
  State() : turn(0), board(3, Vector<int>(3)) {
    for (auto &i : board) {
      for (auto &j : i) {
        j = -1;
      }
    }
  }
};

class Game : public AlphaBeta<int, State> {
private:
  const Vector<Vector<int>> b;
  const Vector<Vector<int>> c;

protected:
  bool isTerminated(const State &state) const { return state.turn == 9; }

  int eval(const State &state) const {
    int res = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (state.board[i][j] == state.board[i + 1][j]) {
          res += b[i][j];
        } else {
          res -= b[i][j];
        }
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (state.board[i][j] == state.board[i][j + 1]) {
          res += c[i][j];
        } else {
          res -= c[i][j];
        }
      }
    }
    return state.turn % 2 ? -res : res;
  }

  Vector<State> next(const State &state) const {
    Vector<State> res;
    State next = state;
    next.turn = state.turn + 1;
    for (auto &i : next.board) {
      for (auto &j : i) {
        if (j != -1) {
          continue;
        }
        j = state.turn % 2;
        res.emplace_back(next);
        j = -1;
      }
    }
    return res;
  }

public:
  Game(const auto &b, const auto &c) : b(b), c(c) {}
};

int main() {
  auto b = Vector<int>::makeVector(in, 2, 3);
  auto c = Vector<int>::makeVector(in, 3, 2);
  int sum = b.accumulate().accumulate() + c.accumulate().accumulate();
  Game game(b, c);
  int res = game.solve(State());
  cout << (sum + res) / 2 << endl << (sum - res) / 2 << endl;
}
