#include <iostream>
#include <vector>

using namespace std;

class ChernobylInt {
public:
  ChernobylInt(int i) {
    while (i) {
      int d { i % 10 };
      i /= 10;
      val.push_back(d);
    }
  }

  void multiplyOn(int n) {
    int quot { };
    for (auto &d: val) {
      int res { d * n + quot };
      quot = res / 10;
      int rem { res % 10 };
      d = rem;
    }
    if (quot) val.push_back(quot);
  }

  operator string() {
    string res { };
    for (auto iter { val.rbegin() }; iter != val.rend(); ++iter)
      res += to_string(*iter);
    return res;
  }

private:
  vector<int> val { };
};

ChernobylInt pow(int n, unsigned int p) {
  ChernobylInt res { 1 };
  for (int i { }; i < p; i++) res.multiplyOn(n);
  return res;
}

int main(int argc, char **argv) {
  int N;
  cin >> N;

  if (N < 5) {
    cout << N;
    return EXIT_SUCCESS;
  }

  int num_3 { N / 3 };
  int rem { N % 3 };

  if (rem == 0) {
    rem = 1;
  } else if (rem == 1) {
    --num_3;
    rem = 4;
  } 

  auto res { pow(3, num_3) };
  res.multiplyOn(rem);
  cout << string(res);

  return EXIT_SUCCESS;
}
