#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void print_map(vector<unsigned> const &hor, vector<unsigned> const &vert) {
  cout << "   ";
  for (auto i: vert) cout << i << "  ";
  cout << endl;
  for (auto i: hor) {
    cout << i << "  ";
    for (auto i: vert) cout << '+' << "  ";
    cout << endl;
  }
}

class Solver {
  public:
  Solver(vector<unsigned> const &vert, vector<unsigned> const &hor):
  vert(vert),
  hor(hor),
  target_x(vert.size() - 1),
  target_y(hor.size() - 1) { }

  void traverse(unsigned x, unsigned y, unsigned min_val) {
    //cout << "TRAV: " << x << ", " << y << ", " << min_val << endl;
    if (x == target_x && y == target_y) {
      //cout << "SUCKCESS: " << min_val << endl;
      result = max(result, min_val);
    }

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

  //print_map(hor, vert);

  cout << s.getResult();

  return EXIT_SUCCESS;
}
