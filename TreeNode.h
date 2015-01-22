#ifndef TREE_NODE_H_
#define TREE_NODE_H_
#include "ListNode.h"

class TreeNode {
public:
  int Value;
  char Data;
  TreeNode* LeftPtr;
  TreeNode* RightPtr;
  

  TreeNode(int sum){
  Value = sum;
  LeftPtr = NULL;
  RightPtr = NULL;
  }

  TreeNode(int value, char ch){
  Value = value;
  Data = Data;
  LeftPtr = NULL;
  RightPtr = NULL;

  }

};

#endif
