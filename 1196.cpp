#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N;
  set<long> teacher { };
  vector<long> student { };
  long buf;

  cin >> N;

  for (int i { }; i < N; ++i) {
    cin >> buf;
    teacher.insert(buf);
  }

  cin >> N;

  student.reserve(N);
  for (int i { }; i < N; ++i) {
    cin >> buf;
    student.push_back(buf);
  }

  cout << count_if(
    student.cbegin(),
    student.cend(),
    [&teacher](auto i) { return teacher.count(i); });
  return EXIT_SUCCESS;
}
