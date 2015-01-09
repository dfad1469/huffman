/*
 * List.h
 *
 *  Created on: Nov 19, 2014
 *      Author: jakob
 */
#ifndef LIST_H_
#define LIST_H_

#include "Tree.h"
#include <cstdlib>

 
class node{

public:
	int count;
	char data;
	node *next;
	node *prev;

	node() {
		count = 1;
		data = 0;
		next = NULL;
		prev = NULL;
	}

};

class List{
private:


	node *head;
	node *curr;
	node *temp;
	biNode *test;


public:

	List();
	void AddNode(char addData);
	void DeleteNode(char delData);
	void PrintList();
	void checkForExisting(char addData);
	void AddToList(char ch);
	void Sort();
	void Swap(node *A, node *B);

};




#endif /* LIST_H_ */
