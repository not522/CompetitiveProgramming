#pragma once
#include "vector.hpp"

template<typename T, typename State, bool Memoize = false> class MinMax {
protected:
  virtual T eval(const State&) const = 0;
  virtual Vector<State> next(const State&) const = 0;
  virtual bool isTerminated(const State& state) const {return next(state).empty();}
  virtual bool used(const State&) const {return false;}
  virtual T memo(const State&) {return T();}
  virtual void use(const State&, const T&) {}

public:
  T solve(const State& state) {
    if (Memoize && used(state)) return memo(state);
    if (isTerminated(state)) return eval(state);
    T score = -inf<T>();
    for (const State& child : next(state)) chmax(score, -solve(child));
    if (Memoize) use(state, score);
    return score;
  }
};
