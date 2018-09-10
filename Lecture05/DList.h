#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

class Item
{
public:
  const char *str;
  Item(const char *s=""):str(s) {}
};

class DList {
private:
  // DListNode represents each
  // node of the list
  class DListNode {
  public:
    Item item;
    DListNode *next;
    DListNode *prev;
    DListNode(Item i,DListNode *n=NULL, DListNode *p=NULL)
    {
      item = i; next = n; prev = p; // constructs the node for us
    }
  };

  // add head and tail pointer
  DListNode *head;
  DListNode *tail;

public:
  class iterator {
  private:
    DListNode *node;

  public:
    iterator(DListNode *n=NULL) { node = n; }
    Item &getItem() { return node->item; }
    void increment() { node = node->next; }
    bool end() {  return node==NULL; }

    friend class DList;
  };

public:
  DList();
  void append(Item a);
  void insertAfter(iterator it, Item a);
  void erase(iterator it);
  bool empty();
};

#endif //DLIST_H
