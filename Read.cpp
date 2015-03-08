#include <fstream>
#include "Read.h"
#include <bitset>

void Read::ReadFile(std::string filename, Tree HuffmanTree, long WriteCount){
  long readCount =0;
  std::ifstream *infile = new std::ifstream(filename.c_str(), std::ifstream::in);

  TreeNode *Node = HuffmanTree.Root;
  char ch;
  while(infile->get(ch)){
  
    
    for(int i = 7; i>=0; i--){
      if(Node->LeftPtr == NULL && Node->RightPtr == NULL){
        std::cout << Node->Data;
        Node = HuffmanTree.Root;
        readCount++;

      if(readCount == WriteCount){
        break;
      }

      }
      if((ch&(1<<i)) ==(1<<i)){
        Node = Node->RightPtr;

      }else{
        Node = Node->LeftPtr;

      }
    }

  }


  std::cout << std::endl;


}
