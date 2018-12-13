#include <stdio.h>
#include <stdlib.h>

enum class Kind { neg_inf = -1, value = 0, pos_inf = 1 };

class IntInf {
protected:
  Kind kind;
  int val;

public:
  bool isInf() const { return kind == Kind::neg_inf || kind == Kind::pos_inf; }
  bool isNegInf() const { return kind == Kind::neg_inf; }
  bool isPosInf() const { return kind == Kind::pos_inf; }

public:
  IntInf(int v = 0) : kind(Kind::value), val(v) {}
  IntInf(Kind k) : kind(k), val(0) {}
  IntInf(const IntInf &copy) : kind(copy.kind), val(copy.val) {}

  IntInf &operator=(const IntInf &rhs) {
    if (this == &rhs)
      return *this;

    kind = rhs.kind;
    val = rhs.val;

    return *this;
  }

  IntInf operator+(const IntInf &rhs) const {
    if (isInf())
      return *this;
    else if (rhs.isInf())
      return rhs;
    else
      return val + rhs.val;
  }

  IntInf operator-() const {
    switch (kind) {
    case Kind::pos_inf:
      return Kind::neg_inf;
    case Kind::neg_inf:
      return Kind::pos_inf;
    case Kind::value:
      return -val;
    }
  }

  IntInf operator-(const IntInf &rhs) const {
    if (isInf())
      return *this;
    else if (rhs.isInf())
      return -rhs;
    else
      return val - rhs.val;
  }

  IntInf operator*(const IntInf &rhs) const {
    if (isNegInf() && rhs.isNegInf())
      return Kind::pos_inf;
    else if (isPosInf() && rhs.isNegInf())
      return Kind::neg_inf;
    else if (isNegInf() && rhs.isPosInf())
      return Kind::neg_inf;
    else if (isPosInf() && rhs.isPosInf())
      return Kind::pos_inf;
    else if (isInf() && !rhs.isInf()) {
      if (rhs.val < 0)
        return -*this;
      else
        return *this;
    } else if (!isInf() && rhs.isInf()) {
      if (val < 0)
        return -rhs;
      else
        return rhs;
    } else
      return val * rhs.val;
  }

  IntInf operator/(const IntInf &rhs) const {
    if (isNegInf() && rhs.isNegInf())
      return Kind::pos_inf;
    else if (isPosInf() && rhs.isNegInf())
      return Kind::neg_inf;
    else if (isNegInf() && rhs.isPosInf())
      return Kind::neg_inf;
    else if (isPosInf() && rhs.isPosInf())
      return Kind::pos_inf;
    else if (isInf() && !rhs.isInf()) {
      if (rhs.val < 0)
        return -*this;
      else
        return *this;
    } else if (!isInf() && rhs.isInf()) {
      return 0;
    } else
      return val / rhs.val;
  }

  bool operator==(const IntInf &rhs) {
    if (isInf())
      return false;
    if (rhs.isInf())
      return false;
    return val == rhs.val;
  }

  bool operator<(const IntInf &rhs) {
    if (isPosInf() && rhs.isPosInf())
      return false;
    if (isNegInf() && rhs.isNegInf())
      return false;
    if (isNegInf() && rhs.isPosInf())
      return true;
    if (isPosInf() && rhs.isNegInf())
      return false;
    if (isInf() && !rhs.isInf()) {
      if (isNegInf())
        return true;
      else
        return false;
    }
    if (!isInf() && rhs.isInf()) {
      if (rhs.isPosInf())
        return true;
      else
        return false;
    }
    return val < rhs.val;
  }

  bool operator>(const IntInf &rhs) {
    if (isPosInf() && rhs.isPosInf())
      return false;
    if (isNegInf() && rhs.isNegInf())
      return false;
    if (isNegInf() && rhs.isPosInf())
      return false;
    if (isPosInf() && rhs.isNegInf())
      return true;

    if (isInf() && !rhs.isInf()) {
      if (isPosInf())
        return true;
      else
        return false;
    }
    if (!isInf() && rhs.isInf()) {
      if (rhs.isNegInf())
        return true;
      else
        return false;
    }
    return val > rhs.val;
  }

  // Print out this object's value
  void print() const {
    if (isPosInf())
      printf("pos_inf");
    else if (isNegInf())
      printf("neg_inf");
    else
      printf("%d", val);
  }

  // Create a random instance of IntInf
  static IntInf random() {
    switch (rand() % 5) {
    case 0:
    case 4:
    case 3:
      return rand() % 10;
    case 1:
      return Kind::neg_inf;
    case 2:
      return Kind::pos_inf;
    }
    return 0;
  }
};

// Print the equation just evaluated, examine output by hand for correctness
void print(const IntInf &r, const IntInf &a, const char *str, const IntInf &b) {
  r.print();
  printf(" = ");
  a.print();
  printf(" %s ", str);
  b.print();
  printf("\n");
}

// Print the equation just evaluaed, examine output by hand for correctness
void print(bool r, const IntInf &a, const char *str, const IntInf &b) {
  printf("%s = ", r ? "true" : "false");
  a.print();
  printf(" %s ", str);
  b.print();
  printf("\n");
}

int main() {

  for (int i = 0; i < 50; i++) {
    IntInf r1 = IntInf::random();
    IntInf r2 = IntInf::random();
    IntInf r3;
    bool r;
    switch (rand() % 8) {
    case 0:
      r3 = r1 + r2;
      print(r3, r1, "+", r2);
      break;
    case 1:
      r3 = r1 - r2;
      print(r3, r1, "-", r2);
      break;
    case 2:
      r3 = r1 * r2;
      print(r3, r1, "*", r2);
      break;
    case 3:
      r3 = r1 / r2;
      print(r3, r1, "/", r2);
      break;
    case 4:
      r = r1 == r2;
      print(r, r1, "==", r2);
      break;
    case 5:
      r = r1 < r2;
      print(r, r1, "<", r2);
      break;
    case 6:
      r = r1 > r2;
      print(r, r1, ">", r2);
      break;
    case 7:
      r3 = r1 + 0;
      print(r3, r1, "+", 0);
      break;
    default:
      break;
    }
  }

  return 0;
}
