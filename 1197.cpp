#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int N;

  cin >> N;

  for (int i { }; i < N; i++) {
    char ch1, ch2;
    array<bool, 8> lost { };

    cin >> ch1 >> ch2;
    int x { ch1 - 'a' }, y { ch2 - '1' };

    if (x < 2) lost[0] = lost[1] = true;
    else if (x > 5) lost[4] = lost[5] = true;

    if (x < 1) lost[2] = lost[7] = true;
    else if (x > 6) lost[3] = lost[6] = true;

    if (y < 2) lost[6] = lost[7] = true;
    else if (y > 5) lost[2] = lost[3] = true;

    if (y < 1) lost[0] = lost[5] = true;
    else if (y > 6) lost[1] = lost[4] = true;

    cout << count(lost.begin(), lost.end(), false) << endl;
  }

  return EXIT_SUCCESS;
}
