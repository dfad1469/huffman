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

#include "ListNode.h" 
#include "TreeNode.h" 

class List{
private:

  ListNode *Head;
  ListNode *Curr;

  TreeNode *test;

public:

  List();
  void AddNode(char addData);
  void DeleteNode(char delData);
  void PrintList();
  void checkForExisting(char addData);
  void AddToList(char ch);
  void Sort();
  void Swap(ListNode *a, ListNode *b);

};

#endif /* LIST_H_ */
