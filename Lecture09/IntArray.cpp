#include "IntArray.h"

IntArray IntArray::operator + (const IntArray &rhs) const
{
  IntArray result(length); // make object to hold return value,
  	                       // make long enough to hold this object’s data
    int i=0;
    for(i=0; i<length && i<rhs.length; i++)
       result.array[i] = array[i] + rhs.array[i];
    for(;i<length;i++) // if rhs.length is shorter, copy rest of array
       result.array[i] = array[i];
    return result;
}


int main()
{
  IntArray x(5);
  x.rand();
  printf("x: ");
  for(int i=0; i<x.getLength(); i++)
  {
    printf("%d ",x.get(i));
  }
  printf("\n");

  IntArray y(5);
  y = x;
  printf("y: ");
  for(int i=0; i<y.getLength(); i++)
  {
    printf("%d ",y.get(i));
  }
  printf("\n");

  IntArray z(5);

  z = x + y;
  
  printf("z: ");
  for(int i=0; i<z.getLength(); i++)
  {
    printf("%d ",z.get(i));
  }
  printf("\n");

  return 0;
}
