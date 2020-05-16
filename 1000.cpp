#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  string line { };
  getline(cin, line);

  istringstream stream {line};

  string token { };
  int sum { };

  while (getline(stream, token, ' ')) {
    sum += stoi(token);
  }

  cout << sum << endl;

  return EXIT_SUCCESS;
}
