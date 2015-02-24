#ifndef LIST_NODE_H_
#define LIST_NODE_H_
#include"TreeNode.h"
#include<iostream>
#include<cstdlib>
class ListNode{

public:
  std::string Path;
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

