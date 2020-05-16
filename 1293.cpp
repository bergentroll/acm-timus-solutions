#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  string input { };
  getline(cin, input);
  int result { 2 };

  istringstream stream { input };
  while(getline(stream, input, ' ')) {
    result *= stoi(input);
  }

  cout << result << endl;

  return EXIT_SUCCESS;
}
