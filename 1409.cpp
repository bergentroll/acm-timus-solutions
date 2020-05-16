#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  unsigned int garry_shot, larry_shot, total;

  cin >> garry_shot >> larry_shot;

  total = garry_shot + larry_shot - 1;

  cout << total - garry_shot << ' ' << total - larry_shot;
}
