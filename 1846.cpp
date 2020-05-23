#include <cstdio>
#include <ios>
#include <unordered_map>

using namespace std;
using uint = unsigned int;

uint euclid_gcd(uint a, uint b) {
  uint tmp { };
  while (b) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

uint process_map(unordered_map<uint, uint> const &collection) {
  if (collection.empty()) return 1;

  uint gcd { (*(collection.begin())).first };
  auto end { collection.end() };
  for (auto it { next(collection.begin()) }; it != end; ++it) {
    gcd = euclid_gcd(gcd, (*it).first);
  }

  return gcd;
}

void insert(unordered_map<uint, uint> &collection, uint num) {
  if (collection.find(num) != collection.end()) ++collection[num];
  else collection[num] = 1;
}

void erase(unordered_map<uint, uint> &collection, uint num) {
  --collection[num];
  if (!collection[num]) collection.erase(num);
}

int main() {
  ios::sync_with_stdio (false);

  int q;
  char op;
  int num;
  unordered_map<uint, uint> collection { };

  scanf("%d\n", &q);

  for (int i { }; i < q; ++i) {
    scanf("%c %d\n", &op, &num);
    if (op == '+') {
      insert(collection, num);
    } else if (op == '-') {
      erase(collection, num);
    }

    printf("%d\n", process_map(collection));
  }

  return EXIT_SUCCESS;
}
