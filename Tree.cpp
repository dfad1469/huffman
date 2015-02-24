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
  for(int i = 0; i<255; i++){
  Dictionary[i]=NULL;
  } 
  temp=NULL;
}



void Tree::BuildTree(List stringData){

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
  TreeNode *next = Root;
  while(next->LeftPtr !=NULL){
    next = next->LeftPtr;
  }

  cout << endl << "The furthest character to the left is " <<  next->Data << " " << next->Value << endl;

  next = Root;

  while(next->RightPtr!=NULL){
    next = next->RightPtr;
  }

}


void Tree::AddNode(ListNode *A, ListNode *B){

  TreeNode *n = new TreeNode();

  if(A->TreeHead != NULL && B->TreeHead == NULL){
    n->LeftPtr = A->TreeHead;
    n->RightPtr = new TreeNode(B->Count,B->Data);
  }else if(A->TreeHead == NULL && B->TreeHead != NULL){
    n->LeftPtr = new TreeNode(A->Count, A->Data);
    n->RightPtr = B->TreeHead;
  }else if(A->TreeHead != NULL && B->TreeHead != NULL){
    n->LeftPtr = A->TreeHead;
    n->RightPtr = B->TreeHead;
  }else{ 
    n->LeftPtr = new TreeNode(A->Count,A->Data);
    n->RightPtr = new TreeNode(B->Count,B->Data);
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
 // ListNode *n = new ListNode();
  Dictionary[(int)root->Data] = new ListNode();
  Dictionary[(int)root->Data]->Path = Path;
  }

  if(root->LeftPtr != NULL){
  PrintTree(root->LeftPtr, Path+'0');
  }
  

  if(root->RightPtr != NULL){
  PrintTree(root->RightPtr, Path+'1');

  }

}


void Tree::PrintDictionary(){
for(int i = 0; i<255; i++){

  if(Dictionary[i] !=NULL){
  cout << (char)i << " " << Dictionary[i]->Path << endl;

  }
 }
}
