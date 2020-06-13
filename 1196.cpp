#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <map>

using namespace std;

int main() {
  int N;
  unordered_set<long> teacher { };
  map<long, int> student { };
  long buf;

  cin >> N;

  for (int i { }; i < N; ++i) {
    cin >> buf;
    teacher.insert(buf);
  }

  cin >> N;

  for (int i { }; i < N; ++i) {
    cin >> buf;
    ++student[buf];
  }

  int acc { };
  for_each(
    student.cbegin(),
    student.cend(),
    [&teacher, &acc](auto i) { if (teacher.count(i.first)) acc += i.second; });

  cout << acc;
  return EXIT_SUCCESS;
}
