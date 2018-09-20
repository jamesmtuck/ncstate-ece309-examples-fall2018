#include <stdio.h>

class Rectangle {
private:
    int width;
    int length;
public:
    Rectangle(int w, int l):width(w),length(l) {}
    int area() { return width * length; }
    void print() { printf("Rectangle"); }
};

class Square : public Rectangle {
public:
    Square(int s):Rectangle(s,s){}
    void print() { printf("Square"); }

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

int main()
{
  Square s(5);
  Rectangle r(4,6);

  Rectangle &ref = s;

  printf("area of s = %d\n", ref.area());
  printf("area of r = %d\n", r.area());
  printf("\n");
  ref.print();printf("\n");
  r.print();printf("\n");
  return 0;
}
