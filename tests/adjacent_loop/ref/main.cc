#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, y, x, h, w;
  cin >> n >> y >> x >> h >> w;
  vector<vector<int>> dy(10), dx(10);
  dy[2] = vector<int>{0, 1};
  dx[2] = vector<int>{1, 0};
  dy[4] = vector<int>{0, -1, 0, 1};
  dx[4] = vector<int>{1, 0, -1, 0};
  dy[5] = vector<int>{0, -1, 0, 1, 0};
  dx[5] = vector<int>{1, 0, -1, 0, 0};
  dy[8] = vector<int>{-1, -1, -1, 0, 0, 1, 1, 1};
  dx[8] = vector<int>{-1, 0, 1, -1, 1, -1, 0, 1};
  dy[9] = vector<int>{-1, -1, -1, 0, 0, 0, 1, 1, 1};
  dx[9] = vector<int>{-1, 0, 1, -1, 0, 1, -1, 0, 1};
  for (int k = 0; k < n; ++k) {
    int i = y + dy[n][k], j = x + dx[n][k];
    if (0 <= i && i < h && 0 <= j && j < w) cout << i << " " << j << endl;
  }
}
