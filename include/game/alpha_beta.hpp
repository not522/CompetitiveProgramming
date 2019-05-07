#pragma once
#include "game/min_max.hpp"

template <typename T, typename State>
class AlphaBeta : public MinMax<T, State> {
protected:
  T solve(const State &state, T alpha, T beta) {
    if (this->isTerminated(state)) {
      return this->eval(state);
    }
    for (const State &child : this->next(state)) {
      alpha = max(alpha, -solve(child, -beta, -alpha));
      if (alpha >= beta) {
        return alpha;
      }
    }
    return alpha;
  }

public:
  T solve(const State &state) { return solve(state, -inf<T>(), inf<T>()); }
};
