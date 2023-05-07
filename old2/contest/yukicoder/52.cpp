#include "queue.hpp"
#include "set.hpp"
#include "string.hpp"

int main() {
  String s(in);
  Queue<Tuple<String, String>> que;
  que.emplace(s, "");
  Set<String> res;
  while (!que.empty()) {
    auto now = que.front();
    if (now.get<0>() == "") {
      res.insert(now.get<1>());
      continue;
    }
    que.emplace(now.get<0>().substr(1), now.get<1>() + now.get<0>()[0]);
    que.emplace(now.get<0>().substr(0, now.get<0>().size() - 1),
                now.get<1>() + now.get<0>().back());
  }
  cout << res.size() << endl;
}
