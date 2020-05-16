#include <iostream>
#include <vector>
#include <cmath>

using namespace::std;

int main(int argc, char **argv) {
  vector<double> vec;
  string line;
  while(cin >> line) {
    vec.push_back(sqrt(stoll(line)));
  }

  cout.precision(4);
  cout << fixed;
  for (auto vec_iter = vec.rbegin(); vec_iter != vec.rend(); vec_iter++) {
      printf("%f\n", *vec_iter);
  }

  return EXIT_SUCCESS;
}
