#ifndef ITEM_H
#define ITEM_H

class Item {
public:
  const char * str;
  Item(const char *as = "")
  {
    str = as;
  }
};

#endif //ITEM_H
