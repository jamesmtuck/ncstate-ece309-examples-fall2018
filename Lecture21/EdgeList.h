#ifndef EDGELIST_H
#define EDGELIST_H

#include <stdlib.h>

class Edge {
public:
  int from;
  int to;
  int weight;
};

class EdgeList {
private:
  // DListNode represents each
  // node of the list
  class ListNode {
  public:
    Edge e;
    ListNode *next;
    ListNode *prev;
    ListNode(Edge i, ListNode *n = NULL, ListNode *p = NULL) {
      e = i;
      next = n;
      prev = p; // constructs the node for us
    }
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
    Edge &getEdge() { return node->e; }
    void increment() { node = node->next; }
    bool end() { return node == NULL; }

    friend class EdgeList;
  };

public:
  EdgeList();
  void append(Edge e);
  void insertAfter(iterator it, Edge e);
  void insertInOrder(Edge e);
  void erase(iterator it);
  bool empty() { return head == NULL; }

  iterator begin() { return iterator(head); }
};

#endif // EDGELIST_H
