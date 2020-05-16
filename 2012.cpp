#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  string input { };
  getline(cin, input);

  int f { stoi(input) };
  int r { 12 - f };

  cout << (r < (5 * 60) / 45? "YES": "NO") << endl;

  return EXIT_SUCCESS;
}
