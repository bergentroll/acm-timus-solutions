#include <iostream>
#include <map>
#include <limits>
#include <cmath>

using namespace std;
using uint = unsigned int;

uint findMin(map<uint, uint> const &collection) {
  auto min { numeric_limits<uint>::max() };
  for (auto [i, j]: collection) {
    if (i < min) min = i;
  }
  return min;
}

bool isDevider(map<uint, uint> const &collection, uint n) {
  for (auto [i, j]: collection) {
    if (i % n) return false;
  }

  return true;
}

uint GCD(map<uint, uint> const &collection) {
  if (collection.empty()) return 1;

  auto const min { findMin(collection) };

  if (isDevider(collection, min)) return min;

  auto min_sqrt { static_cast<uint>(sqrt(min) + 1) };

  for (uint i { min }; i > 1; --i) {
    if (isDevider(collection, i)) return i;
  }

  return 1;
}

void insert(map<uint, uint> &collection, uint num) {
  if (collection.find(num) != collection.end()) ++collection[num];
  else collection[num] = 1;
}

void erase(map<uint, uint> &collection, uint num) {
  --collection[num];
  if (!collection[num]) collection.erase(num);
}

void print(map<uint, uint> collection) {
  for (auto [i, j]: collection) cerr << i << ": " << j << ", ";
  cerr << "END" << endl;
}

int main() {
  int q;
  map<uint, uint> collection { };

  scanf("%d\n", &q);

  for (int i { }; i < q; ++i) {
    char op;
    int num;

    scanf("%c %d\n", &op, &num);
    if (op == '+') {
      insert(collection, num);
    } else if (op == '-') {
      erase(collection, num);
    }

    //print(collection);
    printf("%d\n", GCD(collection));
  }

  return EXIT_SUCCESS;
}
