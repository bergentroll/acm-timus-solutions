#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int N;
  cin >> N;

  map<string, int> count { };
  string buf;
  buf.reserve(30);

  for (int i { }; i < N; ++i) {
    cin >> buf;
    ++count[buf];
  }

  for_each(
    count.cbegin(),
    count.cend(),
    [](auto const &item){if (item.second > 1) cout << item.first << endl; });
  return EXIT_SUCCESS;
}
