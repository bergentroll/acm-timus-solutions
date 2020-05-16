#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int n, guests { };

  cin >> n;

  for (int i { }; i < n; i++) {
    string s;
    cin >> s;
    if (s.find("+one") != string::npos) guests++;
  }

  int total { n + guests + 2 };
  
  cout << (total == 13? 1400: total * 100);

  return EXIT_SUCCESS;
}
