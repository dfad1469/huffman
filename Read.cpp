#include <fstream>
#include "Read.h"
#include <bitset>

void Read::ReadFile(std::string filename, Tree HuffmanTree){

  std::ifstream *infile = new std::ifstream(filename.c_str(), std::ifstream::in);

  TreeNode *Node = HuffmanTree.Root;
  std::cout << Node->LeftPtr->LeftPtr->LeftPtr->RightPtr->Data;   
  char ch;
  int byteLength = 7;
  while(infile->get(ch)){
  std::bitset<8> inCh(ch);
  std::cout<< std::endl << inCh << std::endl;
  
    for(int i = byteLength; i>=0; i--){
      if(Node->LeftPtr == NULL && Node->RightPtr == NULL){
        std::cout << Node->Data;
        Node = HuffmanTree.Root;

      }else if(((ch>>i)&1) == 1){
        Node = Node->RightPtr;

      }else{
        Node = Node->LeftPtr;

      }
    }

  }


  std::cout << std::endl;


}
