#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int a, b, c, res { };

  cin >> a >> b >> c;


  if (c < 3 || b < 2) res = a - b - c;
  else res = a - b * c;

  cout << res;

  return EXIT_SUCCESS;
}
