#include "IntegerSet.h"
#include <stdio.h>
#include <stdlib.h>

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = -1;  // -1 means empty
}

bool IntegerSetHT::insert(int data)
{
   if ( table[hash(data)] == -1)
   {
     // if the entry is not being used, put the
    // data there
     table[ hash(data) ] = data;
     return true;
   }
  // otherwise give up
   return false;
}

bool IntegerSetHT::search(int data) const
{
  // data can only be in one location, check it
  return table[hash(data)]==data;
}

void IntegerSetHT::remove(int data)
{
   if ( table[hash(data)] == data )
       table[hash(data)] = -1;
}


int main()
{
  IntegerSetHT set(1000);

  int count=0;

  while(count < 100)
  {
      int r = rand() % 200;
      if ( !set.search(r) ) {
        if ( set.insert(r) ) {
          count++;
          printf("%d:%d\n",count,r);
        }
      } else {
        printf("????\n");
      }
  }
  return 0;
}
