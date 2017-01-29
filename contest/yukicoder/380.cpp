#include "template.hpp"

int main() {
  map<string, string> m;
  m["digi"] = "nyo";
  m["petit"] = "nyu";
  m["gema"] = "gema";
  m["piyo"] = "pyo";
  string line, name;
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> name;
    if (line == name || !isalpha(line[0])) {
      cout << "WRONG!" << endl;
      continue;
    }
    line = line.substr(name.size() + 1);
    if (name == "rabi") {
      if (find_if(line.begin(), line.end(), [](char c){return isalnum(c);}) != line.end()) {
        cout << "CORRECT (maybe)" << endl;
      } else {
        cout << "WRONG!" << endl;
      }
    } else {
      if (!m.count(name)) {
        cout << "WRONG!" << endl;
        continue;
      }
      for (char& c : line) c = tolower(c);
      reverse(line.begin(), line.end());
      int cnt = find_if(line.begin(), line.end(), [](char c){return isalnum(c);}) - line.begin();
      reverse(line.begin(), line.end());
      if (cnt <= 3 && cnt + m[name].size() <= line.size() && m[name] == line.substr(line.size() - cnt - m[name].size(), m[name].size())) {
        cout << "CORRECT (maybe)" << endl;
      } else {
        cout << "WRONG!" << endl;
      }
    }
  }
}
