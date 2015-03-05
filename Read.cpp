#include <fstream>
#include "Read.h"
#include <bitset>

void Read::ReadFile(std::string filename, Tree HuffmanTree){

  std::ifstream *infile = new std::ifstream(filename.c_str(), std::ifstream::in);

  TreeNode *Node = HuffmanTree.Root;
  std::cout << Node->LeftPtr->LeftPtr->LeftPtr->RightPtr->Data;   
  char ch;
  while(infile->get(ch)){
  
    for(int i = 7; i>=0; i--){
      if(Node->LeftPtr == NULL && Node->RightPtr == NULL){
        std::cout << Node->Data;
        Node = HuffmanTree.Root;

      }else if((ch&(1<<i)) ==(1<<i)){
        Node = Node->RightPtr;

      }else{
        Node = Node->LeftPtr;

      }
      std::bitset<8> byteIn(ch);
      std::cout<< std::endl <<  byteIn << std::endl;
    }

  }


  std::cout << std::endl;


}
