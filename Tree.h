/*
 * Tree.h
 *
 *  Created on: Dec 22, 2014
 *      Author: jakob
 */

#ifndef TREE_H_
#define TREE_H_

#include <cstdlib>
#include "TreeNode.h"
#include "ListNode.h"
#include "List.h"
#include <iostream>

class Tree {
private:

//	TreeNode *Curr;

public:
  Tree();
  void BuildTree(List stringData);
  void AddNode(ListNode *A, ListNode *B );
  void PrintTree(TreeNode *root, unsigned int BiPath,unsigned int Depth);
  TreeNode *Root;
  ListNode *Dictionary[256];
  void PrintDictionary();
  TreeNode *temp;
};

#endif /* TREE_H_ */
