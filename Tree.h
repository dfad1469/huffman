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


class Tree {
private:

	TreeNode *Root;
	TreeNode *Curr;

public:
	Tree();
  void BuildTree(List stringData);
  void AddNode(ListNode *A, ListNode *B );
};

#endif /* TREE_H_ */
