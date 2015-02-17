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


TreeNode *temp;
void Tree::BuildTree(List stringData){

  TreeNode *curr = NULL;

  while(stringData.Length > 1){
   stringData.Sort();
   stringData.PrintList();
   
   cout << "The List is " <<  stringData.Length << " items long." << endl;
   AddNode(stringData.Head,stringData.Head->Next);
   stringData.AddNode(temp);
   stringData.DeleteNode(stringData.Head->Next->Data);
   stringData.DeleteNode(stringData.Head->Data);  
   cout << "The list is now " << stringData.Length << " items long." << endl;
  }

// Testing to see if I can get to the node all the way at the left
  Root = temp;
  curr = Root;
  while(curr->LeftPtr != NULL){
    
  curr = curr->LeftPtr;

  }

  cout << "The furthest node to the left is " << curr->Data << curr->Value << "." << endl;

}


void Tree::AddNode(ListNode *A, ListNode *B){

  TreeNode *n = new TreeNode();

  if(A->TreeHead != NULL && B-> TreeHead == NULL){

    n->LeftPtr = A->TreeHead;
    n->RightPtr = new TreeNode(B->Count,B->Data);
    
   cout << "option A" << endl; 

  }else if(A->TreeHead == NULL && B->TreeHead != NULL){
    n->LeftPtr = new TreeNode(A->Count, A->Data);
    n->RightPtr = B->TreeHead;
  cout << "option B" << endl;


  }else if(A->TreeHead != NULL && B->TreeHead != NULL){
  n->LeftPtr = A->TreeHead;
  n->RightPtr = B->TreeHead;

  cout << "option C" << endl;

  }else{ 

    n->LeftPtr = new TreeNode(A->Count,A->Data);
    n->RightPtr = new TreeNode(B->Count,B->Data);


  cout << "option D" << endl;



  }


  n->Value = n->LeftPtr->Value + n->RightPtr->Value;

  temp = n;

/*  if(Root == NULL){
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
*/
}


void Tree::PrintTree(TreeNode *root, string Path){

  if(root->LeftPtr == NULL && root->RightPtr == NULL){
  cout << root->Data << " " << Path << endl;
  }

  if(root->LeftPtr != NULL){
  PrintTree(root->LeftPtr, Path+'0');
  }
  

  if(root->RightPtr != NULL){
  PrintTree(root->RightPtr, Path+'1');

  }


}
