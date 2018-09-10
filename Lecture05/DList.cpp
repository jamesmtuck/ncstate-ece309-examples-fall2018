#include "DList.h"
#include <stdio.h>

DList::DList()
{
  // initialize empty list
  head = NULL;
  tail = NULL;
}

void DList::append(Item a)
{
  DListNode *node = new DListNode(a,NULL,tail);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else
    {
      tail->next = node;
      tail = node;
    }
}


void DList::insertAfter(DList::iterator it, Item item)
{
  if(head==NULL || it.node == NULL) { // NULL iterator means insert at head
     DListNode *node = new DListNode(item,head); // next=head, prev=NULL
     if (head==NULL) // same as zyBook
        head = tail = node;
     else { // if inserting before head, it.node==NULL
        head->prev = node;
        head = node;
     }
  } else if (it.node == tail) {
     DListNode *node = new DListNode(item,NULL,tail); // next=NULL, prev=old tail
     tail->next = node;
     tail = node;
       } else {
     DListNode *node = new DListNode(item,it.node->next,it.node);
     it.node->next = node;
     node->next->prev = node;
   }

}

void DList::erase(DList::iterator it)
{

}

int main()
{
  DList l;

  l.append("milk");
  l.append("bread");
  l.append("eggs");

/*
  DList::iterator i,j;
  printf("Forward: ");
  for(i = l.begin();!i.end();i.increment())
  {
    Item &item = i.getItem();
    printf("%s ",item.str);
  }

  l.erase(l.rbegin()); // remove the last item in list

  printf("\nIn reverse: ");
  for(j = l.rbegin();!j.end();j.decrement())
  {
    Item &item = j.getItem();
    printf("%s ",item.str);
  }

  printf("\n");
  */
  return 0;
}
