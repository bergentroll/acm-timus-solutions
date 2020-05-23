#include <iostream>

using namespace std;

bool isPalindrome(string const &s) {
  auto const length { s.length() };
  for (size_t i { 0 }, j { length - 1 }; i < length / 2; ++i, --j)
    if (s[i] != s[j]) return false;

  return true;
}

string findPalindrome(string const &S1) {
  string S2 { };

  S2.resize(S1.length());
  copy(S1.rbegin(), S1.rend(), S2.begin());

  string sum { }, addition { };
  for (size_t i { S2.length() - 1 }; i > 0; --i) {
    addition = S2.substr(i);
    sum = S1 + addition;
    if (isPalindrome(sum)) {
      return sum;
    }
  }

  return S1 + S2;
}

int main(int argc, char **argv) {
  string S1 { }, S2 { };
  cin >> S1;

  cout << findPalindrome(S1);

  return EXIT_SUCCESS;
}
