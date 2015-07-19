#include "template.hpp"

int main() {
  string s;
  cin >> s;
  queue<pair<string, string>> que;
  que.push(make_pair(s, ""));
  set<string> res;
  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    if (now.first == "") {
      res.insert(now.second);
      continue;
    }
    que.push(make_pair(now.first.substr(1), now.second + now.first[0]));
    que.push(make_pair(now.first.substr(0, now.first.size() - 1), now.second + now.first.back()));
  }
  cout << res.size() << endl;
}
