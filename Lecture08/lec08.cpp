#include <stdio.h>

class Shape { // Abstract Base Class
public:
  // pure virtual function
  virtual int area() = 0;
  virtual void print() = 0;
};

class Rectangle : public Shape {
private:
  int width;
  int length;

public:
  Rectangle(int w, int l) : width(w), length(l) {}
  int area() { return width * length; }
  virtual void print() { printf("Rectangle"); }
};

class Square : public Rectangle {
public:
  Square(int s) : Rectangle(s, s) {}
  void print() { printf("Square"); }
};

class Circle : public Shape {
private:
  int radius;

public:
  Circle(int r) : radius(r) {}
  int area() { return radius * radius * 3.14; }
};

/*Rectangle::Rectangle(int w, int l)
{
  width = w;
  length = l;
}*/
/*
Square::Square(int side)
:Rectangle(side,side)
{
}*/

void test(Rectangle &r) { r.print(); }

int main() {
  Square s(5);
  Rectangle r(4, 6);

  // Shape &shape = *(new Rectangle(10, 10));

  Rectangle &ref = s;

  printf("area of s = %d\n", ref.area());
  printf("area of r = %d\n", r.area());
  printf("\n");
  ref.print();
  printf("\n");
  r.print();
  printf("\n");
  test(s);
  return 0;
}
