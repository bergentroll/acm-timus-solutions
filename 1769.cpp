#include <iostream>
#include <unordered_set>

using namespace std;

size_t MAX_LENGTH { 6 };

int main() {
  string stone;
  unsigned result { 1 };
  unordered_set<string> grinder;

  cin >> stone;

  size_t stone_length { stone.length() };
  size_t max_length { min(MAX_LENGTH, stone_length) };

  for(size_t length { 1 }; length < max_length + 1; ++length) {
    for(size_t i { 0 }; i < stone_length - length + 1; ++i) {
      auto val { stone.substr(i, length) };
      grinder.insert(val);
    }
  }

  while (true) {
    if (grinder.count(to_string(result)) == 0) {
      cout << result;
      break;
    }
    ++result;
  }

  return EXIT_SUCCESS;
}
