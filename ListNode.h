#ifndef LIST_NODE_H_
#define LIST_NODE_H_
#include"TreeNode.h"
#include<iostream>
#include<cstdlib>
class ListNode{

public:
  int Depth;
  unsigned char BiPath;
  int Count;
  char Data;
  ListNode *Next;
  TreeNode *TreeHead;
  ListNode() {
    BiPath = 0;
    Count = 1;
    Data = 0;
    Next = NULL;
    TreeHead = NULL;
    Depth = 0;
  }

};

#endif /* LIST_NODE_H_ */

