#include <stdio.h>

class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as; 
  }
};


class List {
private:

// ListNode represents each 
// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;	
  public:
    ListNode(Item a) 
    { 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext() 
    { 
      return next; 
    }
    void setNext(ListNode *n) 
    { 
      next = n; 
    }
    Item getItem() 
    { 
      return item; 
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;


  
public:
  List();
  void append(Item a);    
  bool remove(Item &a);    
  bool empty(); 
};

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void List::append(Item a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}


int main()
{
  List l;

  l.append(Item("milk"));
  l.append(Item("eggs"));
  l.append(Item("bread"));
  l.append(Item("potato chips"));
  l.append(Item("toothpaste"));


  while(!l.empty())
    {
      Item copy;
      l.remove(copy);

      printf("Next thing removed: %s\n",copy.str);
    }

  return 0;
}
