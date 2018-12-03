#include <stdio.h>

template <typename T> T max(T a, T b) {
  if (a > b)
    return a;
  else
    return b;
}

class SomeInt {
public:
  int x;
  SomeInt(int ax) : x(ax) {}
  bool operator>(const SomeInt &rhs) { return x > rhs.x; }
};

int main() {

  printf("%d\n", max(34, 55));
  printf("%lf\n", max(6.5, 3.14));

  SomeInt x(5), y(10);
  SomeInt z = max(x, y);

  printf("max = %d\n", z.x);

  return 0;
}
