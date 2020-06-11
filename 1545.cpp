#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Pred {
public:
  Pred(char input): input(input) { }
  bool operator ()(string word) { return word[0] == input; }

private:
  char input;
};

int main() {
  int N;
  set<string> dict { };
  string buf;
  char input;
  cin >> N;
  for (int i { }; i < N; ++i) {
    cin >> buf;
    dict.insert(buf);
  }
  cin >> input;

  auto it { find_if(dict.begin(), dict.end(), Pred(input)) };
  while(it != dict.end()) {
    cout << *it << endl;
    ++it;
    it  = find_if(it, dict.end(), Pred(input));
  }
  return EXIT_SUCCESS;
}
