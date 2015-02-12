#ifndef LIST_NODE_H_
#define LIST_NODE_H_
#include"TreeNode.h"
class ListNode{

public:

  int Count;
  char Data;
  ListNode *Next;
  TreeNode *TreeHead;
  ListNode() {
    Count = 1;
    Data = 0;
    Next = NULL;
    TreeHead = NULL;
  }

};

#endif /* LIST_NODE_H_ */

