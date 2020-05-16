#include <iostream>
#include <vector>

using namespace std;

int normalize(int x) {
  return (x > 0? x: 0);
}

int main() {
  int k, n, res { };
  cin >> k >> n;

  auto a = vector<int>(n);
  int sum { }, acc { };

  for (int i { }; i < n; ++i) {
    cin >> a[i];
  }

  for (auto &item: a) {
    res += item - k;
    res = normalize(res);
  }

  cout << res;

  return EXIT_SUCCESS;
}
