#include <iostream>

using namespace std;
using size = long long;

int main() {
  size R, result { };
  cin >> R;

  size square { R * R };

  size last_y { R - 1 };
  for (size x { }; x < R; ++x) {
    for (size y { last_y }; y > 0; --y) {
      if (x * x + y * y < square) {
        result +=  R - y - 1;
        last_y = y;
        break;
      }
    }
  }

  cout << 4 * (square - result);
}
