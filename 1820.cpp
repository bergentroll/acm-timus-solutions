#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int n, k, res { };

  cin >> n >> k;

  if (k < n) {
    int sides { n * 2 };
    res = sides / k + static_cast<bool>(sides % k);
  }
  else{
    res = 2;
  }

  std::cout << res;

  return EXIT_SUCCESS;
}
