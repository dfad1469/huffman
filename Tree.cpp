/*
 * Tree.cpp
 *
 *  Created on: Dec 22, 2014
 *      Author: jakob
 */
#include "Tree.h"
#include <cstdlib>
#include <iostream>
#include <bitset>

using namespace std;

Tree::Tree() {
  Root = NULL;
  for(int i = 0; i<255; i++){
    Dictionary[i]=NULL;
  } 
  temp=NULL;

  WriteCount = 0;
}

void Tree::BuildTree(List stringData){

  while(stringData.Length > 1){
   stringData.Sort();
   stringData.PrintList();
   
   AddNode(stringData.Head,stringData.Head->Next);
   stringData.AddNode(temp);
   stringData.DeleteNode(stringData.Head->Next->Data);
   stringData.DeleteNode(stringData.Head->Data);  
  }

  Root = temp;

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

}


void Tree::PrintTree(TreeNode *root, unsigned char BiPath, int Depth){

  if(root == NULL) return;

  int tempShift =0;
  char TempPath = 0;
  if(root->LeftPtr == NULL && root->RightPtr == NULL){
  Dictionary[(int)root->Data] = new ListNode();
  for(int i = Depth-1; i>=0;i--){
      if(((BiPath>>i)&1)==1){
        TempPath = TempPath|(1<<tempShift);
      }
      tempShift++;

    }

  Dictionary[(int)root->Data]->BiPath = TempPath;
  Dictionary[(int)root->Data]->Depth = Depth;
  }

  if(root->LeftPtr != NULL){
    PrintTree(root->LeftPtr, BiPath, Depth+1);
  }
  

  if(root->RightPtr != NULL){
    BiPath = BiPath|(1<< Depth);
    PrintTree(root->RightPtr, BiPath, Depth+1);
  }

}


void Tree::PrintDictionary(){
  int treeCount = 0;
  for(int i = 0; i<255; i++){
    if(Dictionary[i] !=NULL){
      bitset<8> path(Dictionary[i]->BiPath);
      if(i == 10){
        cout << "\\n " << path << endl;
      }else{
        cout << (char) i << " " << path << " Length: " << Dictionary[i]->Depth << endl;
      }
      treeCount++;
     }
  }
  //if(this->Root->LeftPtr->LeftPtr->RightPtr->LeftPtr->RightPtr->LeftPtr->RightPtr->LeftPtr->Data !=NULL){
  // cout << this->Root->LeftPtr->LeftPtr->RightPtr->LeftPtr->RightPtr->LeftPtr->RightPtr->LeftPtr->Data << endl;
  //}
  cout << "Items in List: " << treeCount << endl;
}
