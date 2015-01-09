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

int length = 0;

List::List(){
  Head = NULL;
}

void List::AddNode(char addData){

  ListNode *n = new ListNode();
  ListNode *curr = Head;

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

  length++;
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
    cout << delData << " was not in the list" << endl;
    delete delPtr;
  } 
  else
  {
    delPtr = curr;
    curr = curr->Next;
    temp->Next = curr;
    delete delPtr;
    cout << "The vale " << delData << "was deleted" << endl;
  }
}

void List::PrintList(){
  ListNode *curr = Head;

  while(curr->Next != NULL){
    cout << "Node: " << curr->Data << "(" << (int)curr->Data << ")" << curr->Count << endl;
    curr = curr->Next;
  }
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
      cout << ch << " Did not exist in the list and was added."<< endl;
    } else {
      curr->Count++;
      cout << ch << "existed in the list and it's Count was incremented" << endl;
    }
  }
}

void List::Sort(){

  int swap;

  ListNode *curr = Head;

  do{
    swap = 0;
    while(curr->Next != NULL){

      if(curr->Count > curr->Next->Count ){
        Swap(curr,curr->Next);
        swap = 1;
        cout << " Swapped " << curr->Data << " " << curr ->Count << " " << "with "
            << curr->Next->Data << " " << curr->Next->Count << endl;
      }
      curr = curr->Next;
    }
  } while(swap == 1);
}

void List::Swap(ListNode *A, ListNode *B){
  ListNode temp;

  temp.Data = B->Data;
  temp.Count = B->Count;

  B->Data = A->Data;
  B->Count = A->Count;

  A->Count = temp.Count;
  A->Data = temp.Data;
}
