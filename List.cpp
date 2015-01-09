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
  head = NULL;
  curr = NULL;
  temp = NULL;
}


void List::AddNode(char addData){

  node *n = new node();
  n->next = NULL;
  n->prev = NULL;
  n->data = addData;

  if(head != NULL){
    curr = head;

    while(curr->next != NULL){


    curr = curr->next;
    }

    curr->next = n;

  }
  else
  {
    head = n;

  }

  length++;


}

void List::DeleteNode(char delData){
  node *delPtr = NULL;
  temp = head;
  curr = head;

  while(curr != NULL && curr->data != delData){
    temp = curr;
    curr = curr->next;

  }
  if(curr == NULL){
    cout << delData << " was not in the list" << endl;
    delete delPtr;
  }

  else{
    delPtr = curr;
    curr = curr->next;
    temp->next = curr;
    delete delPtr;
    cout << "The vale " << delData << "was deleted" << endl;

  }
}



void List::PrintList(){
  curr = head;
  while(curr->next != NULL){
    cout << "Node: " << curr->data << "(" << (int)curr->data << ")" << curr->count << endl;
    curr = curr->next;
  }

}

void List::AddToList(char ch){
        
  if(head == NULL){
    AddNode(ch);
  }
  else
  {
    curr = head;
    while(curr != NULL && curr->data != ch){
    curr = curr->next;
    }
    if(curr == NULL){
      AddNode(ch);
      cout << ch << " Did not exist in the list and was added."<< endl;
    } else {
      curr->count++;

      cout << ch << "existed in the list and it's count was incremented" << endl;

    }

  }
}

void List::Sort(){

  int swap;
  do{
    swap = 0;
    curr = head;
    while(curr->next != NULL){

      if(curr->count > curr->next->count ){
        Swap(curr,curr->next);
        swap = 1;
        cout << " Swapped " << curr->data << " " << curr ->count << " " << "with "
            << curr->next->data << " " << curr->next->count << endl;
      }
      curr = curr->next;
    }

    } while(swap == 1);
}

void List::Swap(node *A, node *B){
  node *Temp = new node();

  Temp->data = B->data;
  Temp->count = B->count;

  B->data = A->data;
  B->count = A->count;

  A->count = Temp->count;
  A->data = Temp->data;

  delete Temp;
}
