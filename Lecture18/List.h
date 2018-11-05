#ifndef LIST_H
#define LIST_H

#include <stdio.h>

using Item = int;

class List {
private:
  // ListNode represents each
  // node of the list
  class ListNode {
  public:
    Item item; // data in the list
    ListNode *next;

  public:
    ListNode(Item a, ListNode *n = NULL) {
      item = a;
      next = n; // automatically serves as a list tail
    }
    ListNode *getNext() { return next; }
    void setNext(ListNode *n) { next = n; }
    Item &getItem() { return item; }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public:
  class iterator {
  private:
    ListNode *node;

  public:
    iterator(ListNode *n = NULL) { node = n; }
    Item &getItem() { return node->getItem(); }
    void increment() { node = node->next; }
    bool end() { return node == NULL; }

    friend class List;
  };

public:
  List();
  void append(Item a);
  bool remove(Item &a);
  bool empty();

  iterator begin() { return iterator(head); }

  void removeAfter(iterator it); // pseudocode in zyBook 2.4
  void insertAfter(iterator it, Item item);
};

#endif // LIST_H
