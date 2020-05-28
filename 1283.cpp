#include <iostream>

using namespace std;

int main() {
  double pot;
  int threshold, tax, counter { 0 };
  cin >> pot >> threshold >> tax;

  while (pot > threshold) {
    pot = pot * (100 - tax) / 100;
    ++counter;
  }

  cout << counter;
  return EXIT_SUCCESS;
}
