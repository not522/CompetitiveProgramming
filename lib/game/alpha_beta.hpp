#pragma once
#include "template.hpp"

template<typename T, typename State> class AlphaBeta {
protected:
  virtual bool isTerminated(const State&) const = 0;
  virtual T eval(const State&) const = 0;
  virtual vector<State> next(const State&) const = 0;
  
  T solve(const State& state, int depth, T alpha, T beta) {
    if (depth == 0 || isTerminated(state)) return eval(state);
    for (const State& child : next(state)) {
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
