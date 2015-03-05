/*
 * main.cpp
 *
 *  Created on: Nov 30, 2014
 *      Author: jakob
 */

#include<cstdlib>
#include "List.h"
#include <fstream>
#include <iostream>
#include "Tree.h"
#include "Writer.h"
#include "Read.h"
using namespace std;

int main(int argc, const char* argv[]){

  List Text;
  Tree HuffmanTree;
  Writer Translator;
  Read Reader;
  if(argc != 2) {
    cout << "Usage: huff <filename>" << endl;
    return 1;
  }

  ifstream text(argv[1]);

  char ch;
  while(text.get(ch)){
    Text.AddToList(ch);
  }

  text.close();

  Text.PrintList();

  HuffmanTree.BuildTree(Text);
  HuffmanTree.PrintTree(HuffmanTree.Root, 0,0);  
  HuffmanTree.PrintDictionary();
  Translator.Translate(HuffmanTree.Dictionary,argv[1]);
  cout << HuffmanTree.Root->LeftPtr->LeftPtr->LeftPtr->RightPtr->Data << endl;
  Reader.ReadFile(argv[1],HuffmanTree);
  
  return 0;
}


