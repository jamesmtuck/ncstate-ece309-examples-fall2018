
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  vector<int> v(5, 0); // declare a vector with 5 zeros
  // print them out, all zeros
  for (int i = 0; i < v.size(); i++)
    printf("%d ", v[i]); // access using array notation or using an iterator
  printf("\n");

  v[1] = 1;
  v[2] = 2;
  v[3] = 3;
  v[4] = 4; // modify contents using operator[]

  v.resize(10, -1); // make array of length 10, put -1 in new spots

  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    printf("%d ", *it);
    (*it)++;
  }
  printf("\n");

  for (int i = 0; i < v.size(); i++)
    printf("%d ", v[i]); // prints: 0 1 2 3 4 -1 -1 -1 -1 -1
  printf("\n");
  return 0;
}
