#include <iostream>

using namespace std;

int main() {
  string s;

  cin >> s;

  unsigned result { 1 };
  while(true) {
    auto it { s.find(to_string(result)) };
    if (it == s.npos) break;
    ++result;
  }

  cout << result;
  return EXIT_SUCCESS;
}
