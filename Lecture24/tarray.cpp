template <typename T = int, int length = 10> class TArray {
public:
  T value[length];
};

TArray<> ex;
TArray<int> iarray;
TArray<double, 50> darray;
TArray<SomeInt, 10> sarray;
