#include <iostream>
#include <map>

using namespace std;

int main() {
  unsigned n, p;
  map<unsigned, unsigned> a;

  cin >> n >> p;

  for (unsigned i { }; i < n; ++i) {
    unsigned buf;
    cin >> buf;
    ++a[buf];
  }

  unsigned
    acc { },
    total_amount { },
    cast_num { };

  auto end { a.cend() };

  for (auto it { a.cbegin() }; it != end; ++it) {
    unsigned power { (acc + it->second) * it->first};

    if (power > p) {
      if (acc == 0) break;

      total_amount += acc;
      ++cast_num;
      acc = 0;
      --it;
    }
    else {
      acc += it->second;
    }
  }

  total_amount += acc;
  cast_num += (acc > 0);

  cout << total_amount << ' ' << cast_num;

  return EXIT_SUCCESS;
}
