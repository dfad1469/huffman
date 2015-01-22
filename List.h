/*
 * List.h
 *
 *  Created on: Nov 19, 2014
 *      Author: jakob
 */
#ifndef LIST_H_
#define LIST_H_

#include <cstdlib>

#include "ListNode.h" 
#include "TreeNode.h" 

class List{
private:

public:
  ListNode *Head;
  ListNode *Curr;

  TreeNode *Test;

  List();
  
  void AddNode(char addData);
  void AddNode(TreeNode *TreeItem);
  void DeleteNode(char delData);
  void PrintList();
  void checkForExisting(char addData);
  void AddToList(char ch);
  void Sort();
  void Swap(ListNode *a, ListNode *b);

  int Length;
};

#endif /* LIST_H_ */
