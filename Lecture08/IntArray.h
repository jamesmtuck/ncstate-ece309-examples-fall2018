#ifndef INTARRAY_H
#define INTARRAY_H

#include <stdio.h>

class IntArray {
private:
   int *array;
   int length;
public:
   IntArray(int le, int val=0):length(le) {
      array = new int[le];
      for(int i=0; i<le; i++)
        array[i] = val;
   }

  ~IntArray() { delete [] array; }

   int get(int index) {
       return array[index];
   }
};

#endif //INTARRAY_H
