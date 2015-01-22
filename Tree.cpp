/*
 * Tree.cpp
 *
 *  Created on: Dec 22, 2014
 *      Author: jakob
 */
#include "Tree.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Tree::Tree() {
  Root = NULL;
}


void Tree::BuildTree(List stringData){
  while(stringData.Length > 1){
   stringData.Sort();
   stringData.PrintList();
   
   cout << "The List is " <<  stringData.Length << " items long." << endl;
   AddNode(stringData.Head,stringData.Head->Next);
   stringData.AddNode(this->Root);
   stringData.DeleteNode(stringData.Head->Next->Data);
   stringData.DeleteNode(stringData.Head->Data);  
   cout << "The list is now " << stringData.Length << " items long." << endl;
  }
}


void Tree::AddNode(ListNode *A, ListNode *B){


  if(Root == NULL){
  Root = new TreeNode(A->Count + B->Count);
  Root->LeftPtr = new TreeNode(A->Count, A->Data);
  Root->Data = '?';
  Root->RightPtr = new TreeNode(B->Count, B->Data);
  
  cout << endl <<"  " << Root->Value <<"  "  << endl;
  cout <<Root->LeftPtr->Value << "  " << Root->RightPtr->Value << endl;

  }else{

  TreeNode *rightNode =  new TreeNode(A->Count + B->Count);
  TreeNode *temp = new TreeNode(Root->Value + rightNode->Value);
  temp->LeftPtr = Root;
  temp->RightPtr = rightNode;
  Root = temp;
  
  cout << endl <<"  " << Root->Value <<"  "  << endl;
  cout <<Root->LeftPtr->Value << "  " << Root->RightPtr->Value << endl;
  
  
  }

}

