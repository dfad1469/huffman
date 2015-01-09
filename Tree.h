/*
 * Tree.h
 *
 *  Created on: Dec 22, 2014
 *      Author: jakob
 */

#ifndef TREE_H_
#define TREE_H_

class biNode {
public:
	char data;
	biNode* leftPtr;
	biNode* rightPtr;
};

class Tree {
private:

	biNode *root;
	biNode *curr;

public:
	Tree();
	void addNode();

};

#endif /* TREE_H_ */
