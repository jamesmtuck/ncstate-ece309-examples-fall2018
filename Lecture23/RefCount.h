#ifndef REFCOUNT_H
#define REFCOUNT_H

// RefCount.h

class RefCount {
private:
  static int count;

public:
  static int getCount();
  RefCount() { count++; }
  ~RefCount() { count--; }
};
#endif
