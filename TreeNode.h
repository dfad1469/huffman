#include<iostream>
#include<cstdlib>

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

class TreeNode {
public:
  int Value;
  char Data;
  TreeNode* LeftPtr;
  TreeNode* RightPtr;
  std::string Path;

 
  TreeNode(){
    Value = 0;
    LeftPtr= NULL;
    RightPtr = NULL;
    Data = 0;
  } 

  TreeNode(int sum){
    Value = sum;
    LeftPtr = NULL;
    RightPtr = NULL;
  }

  TreeNode(int value, char ch){
    Value = value;
    Data = ch;
    LeftPtr = NULL;
    RightPtr = NULL;
  }

};

#endif
