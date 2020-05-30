#include <cstdio>

unsigned min(unsigned a, unsigned b) {
  return a < b? a: b;
}

unsigned max(unsigned a, unsigned b) {
  return a < b? b: a;
}

int main() {
  unsigned n, m, buf, max_vert, max_hor, first_vert, last_vert, first_hor, last_hor;

  scanf("%u %u\n", &n, &m);

  for (unsigned i { }; i < n; ++i) {
    scanf("%u\n", &buf);
    if (i == 0) {
      max_vert = buf;
      first_vert = buf;
    }
    max_vert = max(max_vert, buf);
  }
  last_vert = buf;

  for (unsigned i { }; i < m; ++i) {
    scanf("%u\n", &buf);
    if (i == 0) {
      max_hor = buf;
      first_hor = buf;
    }
    max_hor = max(max_hor, buf);
  }
  last_hor = buf;

  printf("%u", max(max(min(first_vert, last_hor), min(last_vert, first_hor)), max(min(min(first_vert, last_vert), max_hor), min(min(first_hor, last_hor), max_vert))));

  return 0;
}
