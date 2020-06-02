#include <iostream>

using namespace std;

int vacant_days(int n) {
  int
    val { n },
    level { 2 },
    prev { 0 };

  while (val != prev) {
    prev = val;
    val -= val / level;
    if (val == prev) break;
    ++level;
  }
  return val;
}

int main() {
  int l, r;

  cin >> l >> r;


  cout << vacant_days(r) - vacant_days(l- 1);
}
