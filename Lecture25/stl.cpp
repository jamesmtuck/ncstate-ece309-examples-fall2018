#include <set>
#include <stdio.h>
#include <unordered_set>

int main() {
  std::unordered_set<int> s;

  for (int i = 0; i < 10; i++) {
    s.insert(rand() % 100);
  }

  std::unordered_set<int>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    printf("%d ", *it);
  }

  return 0;
}
