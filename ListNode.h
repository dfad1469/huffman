#ifndef LIST_NODE_H_
#define LIST_NODE_H_
class ListNode{

public:

  int Count;
  char Data;
  ListNode *Next;

  ListNode() {
    Count = 1;
    Data = 0;
    Next = NULL;
  }

};

#endif /* LIST_NODE_H_ */

