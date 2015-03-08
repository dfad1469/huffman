/*
 * List.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: jakob
 */
#include <cstdlib>
#include <iostream>

#include "List.h"
#include "Tree.h"

using namespace std;


List::List(){
  Head = NULL;
  Length = 0;
}

void List::AddNode(char addData){

  ListNode *n = new ListNode();
  ListNode *curr = Head;
  
  n->TreeHead = NULL;
  n->Next = NULL;
  n->Data = addData;

  if(Head != NULL){
    curr = Head;

    while(curr->Next != NULL){
      curr = curr->Next;
    }

    curr->Next = n;
  }
  else
  {
    Head = n;
  }
  Length++;
}

void List::AddNode(TreeNode *treeItem){

  ListNode *n = new ListNode();
  ListNode *curr = Head;

  n->Next = NULL;
  n->Count = treeItem->Value;
  n->Data = '?';
  n->TreeHead = treeItem;
  if(Head != NULL){
    curr = Head;

    while(curr->Next != NULL){
      curr = curr->Next;
    }

    curr->Next = n;
  }
  else
  {
    Head = n;
  }
  Length++;
  


}

void List::DeleteNode(char delData){
  ListNode *delPtr = NULL;

  ListNode *temp = Head;
  ListNode *curr = Head;

  while(curr != NULL && curr->Data != delData){
    temp = curr;
    curr = curr->Next;
  }

  if(curr == NULL){
//    cout << delData << " was not in the list" << endl;
    delete delPtr;
  } 

  else if(curr == Head){
  Head = curr->Next;
  delete curr;
//  cout << "The Head of the list was deleted." << endl;

  }

  else
  {
    delPtr = curr;
    curr = curr->Next;
    temp->Next = curr;
    delete delPtr;
//    cout << "The value " << delData << "was deleted" << endl;
  }

  Length--;
}

void List::PrintList(){
  ListNode *curr = Head;

  while(curr != NULL){
    cout << "Node: " << curr->Data << "(" << (int)curr->Data << ")" << curr->Count << endl;
    curr = curr->Next;
  }
  cout << "List Length: " << Length << endl;	
}

void List::AddToList(char ch){

  ListNode *curr = Head;
        
  if(Head == NULL){
    AddNode(ch);
  }
  else
  {
    while(curr != NULL && curr->Data != ch){
      curr = curr->Next;
    }
    if(curr == NULL){
      AddNode(ch);
//      cout << ch << " Did not exist in the list and was added."<< endl;
    } else {
      curr->Count++;
//      cout << ch << "existed in the list and it's Count was incremented" << endl;
    }
  }
}

void List::Sort(){
  int swap;

  do{
    ListNode *curr = Head;
    swap = 0;
    while(curr->Next != NULL){

      if(curr->Count > curr->Next->Count ){
        Swap(curr,curr->Next);
        swap = 1;
      }
      curr = curr->Next;
    }
  } while(swap == 1);
}

void List::Swap(ListNode *A, ListNode *B){
  ListNode temp;

  temp.TreeHead = B->TreeHead;
  temp.Data = B->Data;
  temp.Count = B->Count;

  B->Data = A->Data;
  B->Count = A->Count;
  B->TreeHead = A->TreeHead;

  A->TreeHead = temp.TreeHead;
  A->Count = temp.Count;
  A->Data = temp.Data;

//  cout << " Swapped " << B->Data << " " << B->Count << " " << "with "
//       << A->Data << " " << A->Count << endl;
}
