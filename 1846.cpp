#include <cstdio>
#include <ios>
#include <unordered_map>
#include <limits>
#include <cmath>

using namespace std;
using uint = unsigned int;

uint findMin(unordered_map<uint, uint> const &collection) {
  auto min { numeric_limits<uint>::max() };
  for (auto const &i: collection) {
    if (i.first < min) min = i.first;
  }
  return min;
}

uint SumSqrt(unordered_map<uint, uint> const &collection) {
  unsigned long long sum { };
  for (auto const &i: collection) {
    sum += i.first;
  }
  return sqrtl(sum);
}

bool isDevider(unordered_map<uint, uint> const &collection, uint n) {
  for (auto const &i: collection) {
    if (i.first % n) return false;
  }

  return true;
}

uint GCD(unordered_map<uint, uint> const &collection) {
  if (collection.empty()) return 1;

  auto const min { findMin(collection) };

  if (isDevider(collection, min)) return min;

  auto min_sqrt { static_cast<uint>(sqrtl(min)) };
  //auto sum_sqrt { SumSqrt(collection) };

  for (uint i { min_sqrt }; i > 1; --i) if (isDevider(collection, i)) return i;

  return 1;
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

    printf("%d\n", GCD(collection));
  }

  return EXIT_SUCCESS;
}
