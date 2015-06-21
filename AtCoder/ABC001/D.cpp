#include "template.hpp"

void output(int s, int e) {
  cout << setw(4) << setfill('0') << s << "-" << setw(4) << setfill('0') << e << endl;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> d;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    str[4] = ' ';
    stringstream ss(str);
    int s, e;
    ss >> s >> e;
    s -= s % 5;
    e += 4;
    e -= e % 5;
    if (e % 100 == 60) e += 40;
    d.emplace_back(make_pair(s, e));
  }
  sort(d.begin(), d.end());
  int t = 0;
  for (int i = 1; i < n; ++i) {
    if (d[t].second >= d[i].first) {
      d[t].second = max(d[t].second, d[i].second);
    } else {
      output(d[t].first, d[t].second);
      t = i;
    }
  }
  output(d[t].first, d[t].second);
}
