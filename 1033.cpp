#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Map = vector<vector<bool>>;

void print(Map const &map) {
  for (auto i: map) {
    for (auto j: i) {
      cerr << (j? '+': '-');
    }
    cerr << endl;
  }
  cerr << endl;
}

void traverse(Map const &map, Map &visited, int x, int y, size_t &walls) {
  visited[x][y] = true;

  auto max_index { map.size() };

  for (int i { -1 }; i < 2; ++i) {
    for (int j { -1 }; j < 2; ++j) {
      if ((i == 0 && j == 0) || (i != 0 && j != 0)) continue;
      auto new_x { x + i };
      auto new_y { y + j };
      if (
          new_x < max_index &&
          new_x > -1 &&
          new_y < max_index &&
          new_y > -1 &&
          !map[new_x][new_y]) {
            if (!visited[new_x][new_y]) {
              traverse(map, visited, new_x, new_y, walls);
            }
      }
      else {
        ++walls;
      }
    }
  }
}

int main() {
  size_t N { };

  cin >> N;

  Map map { };
  map.reserve(N);

  for (int i { }; i < N; ++i) {
    string buf { };
    buf.reserve(N);
    cin >> buf;
    vector<bool> line;
    line.reserve(N);

    for_each(
      buf.cbegin(),
      buf.cend(),
      [&line](auto item) { line.push_back(item == '.'? false: true); });

    map.push_back(line);
  }

  //print(map);

  size_t walls { };

  Map visited { };
  visited.reserve(N);

  for (int i { }; i < N; ++i) {
    auto line = vector<bool>(N, false);
    visited.push_back(line);
  }

  traverse(map, visited, 0, 0, walls);
  //print(visited);
  if (!visited[N -1][N - 1]) traverse(map, visited, N - 1, N - 1, walls);
  //print(visited);

  cout << (walls - 4) * 9;

  return EXIT_SUCCESS;
}
