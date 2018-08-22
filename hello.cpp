#include <stdio.h>

class Rectangle {
private:
  int width;
  int length;
  int area()
  {
    return width*length;
  }
};


struct rectangle {
  int width;
  int length;
};

int area(int w, int l)
{
  return w*l;
}

int main()
{
  struct rectangle r1 = { 3, 4 };
  struct rectangle r2 = { 10, 12 };

  Rectangle r;
  r.width = 5;
  r.length = 10;

  printf("Hello, World! area = %d\n", r.area());
  return 0;
}
