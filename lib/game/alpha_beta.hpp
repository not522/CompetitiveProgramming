#pragma once
#include "game/min_max.hpp"

template<typename T, typename State> class AlphaBeta : public MinMax<T, State> {
protected:
  T solve(const State& state, int depth, T alpha, T beta) {
    if (depth == 0 || this->isTerminated(state)) return this->eval(state);
    for (const State& child : this->next(state)) {
      alpha = max(alpha, -solve(child, depth - 1, -beta, -alpha));
      if (alpha >= beta) return alpha;
    }
    return alpha;
  }

public:
  T solve(const State& state, int depth = numeric_limits<int>::max()) {
    return solve(state, depth, -numeric_limits<T>::min() + 1, numeric_limits<T>::max());
  }
};
