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

using namespace std;

int main(int argc, const char* argv[]){

	List Text;
  Tree HuffmanTree;

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
  HuffmanTree.BuildTree(Text);
   

 
	
	return 0;
}


