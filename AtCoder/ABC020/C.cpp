#include "graph/edge.hpp"
#include "graph/adjacency_list.hpp"
#include "graph/shortest_path.hpp"
#include "binary_search.hpp"

class Wall : public BinarySearch {
private:
  typedef AdjacencyList<WeightedEdge<long long>> Graph;

  vector<string> s;
  int t;
  
  bool valid(long long n) {
    int h = s.size();
    int w = s.front().size();
    Graph graph(h * w);
    const int dy[] = {0, -1, 0, 1};
    const int dx[] = {1, 0, -1, 0};
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int k = 0; k < 4; ++k) {
          int ii = i + dy[k];
          int jj = j + dx[k];
          if (ii < 0 || h <= ii) continue;
          if (jj < 0 || w <= jj) continue;
          graph.addEdge(i * w + j, ii * w + jj, s[ii][jj] == '#' ? n : 1);
        }
      }
    }
    int a = -1, b = -1;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (s[i][j] == 'S') a = i * w + j;
        if (s[i][j] == 'G') b = i * w + j;
      }
    }
    return shortestPath(graph, a, b) <= t;
  }

public:
  Wall(const vector<string>& s, long long t) : BinarySearch(1, t), s(s), t(t) {}
};

int main() {
  int h, w, t;
  cin >> h >> w >> t;
  vector<string> s(h);
  for (auto& i : s) cin >> i;
  Wall wall(s, t);
  cout << wall.solve() << endl;
}
