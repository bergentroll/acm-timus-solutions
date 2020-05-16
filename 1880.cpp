#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  vector<long> numbers { };
  set<long> numbers_set { };

  for (int i { }; i < 3; i++) {
    int amount;
    cin >> amount;

    for (int j { }; j < amount; j++) {
      long num;
      cin >> num;
      numbers.push_back(num);
      numbers_set.insert(num);
    }
  }

  int result { };

  for (auto i: numbers_set)
    if (count(numbers.begin(), numbers.end(), i) == 3) result++;

  cout << result;

  return EXIT_SUCCESS;
}
