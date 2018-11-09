

class IntArray {
protected:
  int *array;
  int size;

public:
  IntArray(int sz = 1000) {
    array = new int[sz];
    size = sz;
  }

  int &operator[](int i) {
    /*if (i < 0 || i >= size)
      return 0;*/

    return array[i];
  }

  IntArray(const IntArray &copy) {
    size = copy.size;
    array = new int[size];
    for (int i = 0; i < size; i++)
      array[i] = copy[i];
  }

  IntArray &operator=(const IntArray &rhs) {
    if (&rhs == this)
      return *this;
    delete[] array;
    size = rhs.size;
    array = new int[size];
    for (int i = 0; i < size; i++)
      array[i] = rhs[i];
    return *this;
  }
};
