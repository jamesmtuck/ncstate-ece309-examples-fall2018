#include "Queue.h"

int main()
{
  Queue q;

  q.push("milk");
  q.push("bread");
  q.push("eggs");

  while(!q.empty())
  {
    Item &i = q.peek();
    printf("%s\n",i.str);
    q.pop();
  }

  return 0;
}
