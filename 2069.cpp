#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

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

  unsigned var1 { max(min(vert.front(), hor.back()), min(vert.back(), hor.front())) };
  unsigned var2 { max(
    min(min(vert.front(), vert.back()), *max_element(next(hor.begin()), prev(hor.end()))),
    min(min(hor.front(), hor.back()), *max_element(next(vert.begin()), prev(vert.end())))) };

  cout << max(var1, var2);

  return EXIT_SUCCESS;
}
