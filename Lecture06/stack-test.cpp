#include "Stack.h"

int main()
{
  Stack s;

  s.push("milk");
  s.push("eggs");
  s.push("bread");

  while(!s.empty())
  {
    Item &i = s.peek();
    printf("%s\n",i.str);
    s.pop();
  }

  return 0;
}
