#include <list>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
  list<const char *> l;
  using iterator = list<const char *>::iterator;

  l.push_back("eggs");
  l.push_front("milk");

  iterator it;
  for (it = l.begin(); it != l.end(); it++)
    printf("%s ", (*it));

  return 0;
}
