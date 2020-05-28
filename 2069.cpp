#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solver {
  public:
  Solver(vector<unsigned> const &vert, vector<unsigned> const &hor):
  vert(vert),
  hor(hor),
  target_x(vert.size() - 1),
  target_y(hor.size() - 1) { }

  void traverse(unsigned x, unsigned y, unsigned min_val) {
    if (x == target_x && y == target_y) {
      result = max(result, min_val);
      return;
    }

    if (min_val <= result) return;

    if (x < target_x) {
      traverse(x + 1, y, min(min_val, hor[y]));
    }
    if (y < target_y) {
      traverse(x, y + 1, min(min_val, vert[x]));
    }
  }

  unsigned getResult() { return result; }

  private:
  vector<unsigned> const &vert, &hor;
  unsigned target_x, target_y;
  unsigned result { numeric_limits<unsigned>::min() };
};

int main() {
  unsigned n, m;
  cin >> n >> m;

  vector<unsigned> hor { }, vert { };

  unsigned buf;
  for (unsigned i { }; i < n; ++i) {
    cin >> buf;
    vert.push_back(buf);
  }
  for (unsigned i { }; i < m; ++i) {
    cin >> buf;
    hor.push_back(buf);
  }

  Solver s { vert, hor };

  s.traverse(0, 0, numeric_limits<unsigned>::max());

  cout << s.getResult();

  return EXIT_SUCCESS;
}
