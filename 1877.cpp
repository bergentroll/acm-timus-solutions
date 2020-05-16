#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  unsigned int code1, code2;

  cin >> code1 >> code2;

  cout << ((!(code1 % 2) || code2 % 2)? "yes": "no");
}
