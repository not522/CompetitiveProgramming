#include "string.hpp"

int main() {
  setBoolName("CORRECT (maybe)", "WRONG!");
  Map<String, String> m;
  m["digi"] = "nyo";
  m["petit"] = "nyu";
  m["gema"] = "gema";
  m["piyo"] = "pyo";
  String line, name;
  while (line = String::getline(), !in.eof) {
    if (line == "" || line[0] == ' ') {
      cout << false << endl;
      continue;
    }
    name = line.split()[0];
    if (line == name) {
      cout << false << endl;
      continue;
    }
    line = line.substr(name.size() + 1);
    if (name == "rabi") {
      cout << line.any_of([](char c) { return isalnum(c); }) << endl;
    } else if (!m.contains(name)) {
      cout << false << endl;
    } else {
      line.tolower().reverse();
      int cnt = line.find_if([](char c) { return isalnum(c); });
      if (cnt > 3 || cnt + m[name].size() > line.size()) {
        cout << false << endl;
        continue;
      }
      cout << (line.substr(cnt, m[name].size()).reverse() == m[name]) << endl;
    }
  }
}
