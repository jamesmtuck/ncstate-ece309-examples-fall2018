#include "DList.h"
#include <stdio.h>

DList::DList() {
  // initialize empty list
  head = NULL;
  tail = NULL;
}

void DList::append(Item a) {
  DListNode *node = new DListNode(a, NULL, tail);
  if (head == NULL) {
    // list is empty
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

void DList::insertAfter(DList::iterator it, Item item) {
  if (head == NULL || it.node == NULL) { // NULL iterator means insert at head
    DListNode *node = new DListNode(item, head); // next=head, prev=NULL
    if (head == NULL)                            // same as zyBook
      head = tail = node;
    else { // if inserting before head, it.node==NULL
      head->prev = node;
      head = node;
    }
  } else if (it.node == tail) {
    DListNode *node =
        new DListNode(item, NULL, tail); // next=NULL, prev=old tail
    tail->next = node;
    tail = node;
  } else {
    DListNode *node = new DListNode(item, it.node->next, it.node);
    it.node->next = node;
    node->next->prev = node;
  }
}

void DList::erase(DList::iterator it) {
  DListNode *succ = it.node->next; // successor node
  DListNode *pred = it.node->prev; // predecessor node

  if (succ != NULL)
    succ->prev = pred;
  if (pred != NULL)
    pred->next = succ;

  if (it.node == head)
    head = succ; // head is following node
  if (it.node == tail)
    tail = pred; // tail is previous node

  delete it
      .node; // delete the node; not shown in zyBook, but necessary in C/C++
  // iterator is now invalid, caller should not use it again
}
