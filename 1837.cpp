#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
  string root { "Isenbaev" };

  int N;
  cin >> N;

  array<string, 3> buf { };
  unordered_map<string, unordered_set<string>> relations { };
  for (int i { }; i < N; ++i) {
    cin >> buf[0] >> buf[1] >> buf[2];
    for (auto const &person: buf) {
      for (auto const &partner: buf) {
        if (partner != person) relations[person].insert(partner);
      }
    }
  }

  // Item is { last_name, level }.
  queue<pair<string, int>> targets { };
  unordered_set<string> processed { root };
  int level { };
  vector<string> result { }; result.reserve(relations.size());

  if (relations.count(root)) targets.push(make_pair(root, 0));

  while (!targets.empty()) {
    auto target { targets.front() }; targets.pop();
    result.push_back(target.first + ' ' + to_string(target.second));
    for (auto const &person: relations[target.first]) {
      if (!processed.count(person)) {
        targets.push(make_pair(person, target.second + 1));
        processed.insert(person);
      }
    }
  }

  for (auto const &[person, partners]: relations)
    if (!processed.count(person)) result.push_back(person + " undefined");

  sort(result.begin(), result.end());

  for (auto const &line: result) cout << line << endl;

  return EXIT_SUCCESS;
}
