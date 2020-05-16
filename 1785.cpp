#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  string input { };
  int value { };

  while(getline(cin, input)) {
    value = stoi(input);

    if (value < 5) {
      cout << "few" << endl;
      continue;
    }
    if (value < 10) {
      cout << "several" << endl;
      continue;
    }
    if (value < 20) {
      cout << "pack" << endl;
      continue;
    }
    if (value < 50) {
      cout << "lots" << endl;
      continue;
    }
    if (value < 100) {
      cout << "horde" << endl;
      continue;
    }
    if (value < 250) {
      cout << "throng" << endl;
      continue;
    }
    if (value < 500) {
      cout << "swarm" << endl;
      continue;
    }
    if (value < 1000) {
      cout << "zounds" << endl;
      continue;
    }

    cout << "legion" << endl;
  }

  return EXIT_SUCCESS;
}
