/*
 * Tree.h
 *
 *  Created on: Dec 22, 2014
 *      Author: jakob
 */

#ifndef TREE_H_
#define TREE_H_

#include "TreeNode.h"

class Tree {
private:

	TreeNode *Root;
	TreeNode *Curr;

public:
	Tree();
	void AddNode();
};

#endif /* TREE_H_ */
