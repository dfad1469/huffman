#include"Writer.h"
#include <bitset>
#include <cstdlib>

using namespace std;

void Writer::Translate(ListNode *Dictionary[], std::string filename, long &WriteCount){
  char buffer = 0;
  int byteLength = 0;
  char *writeBuffer;
  
  std::ifstream *infile = new std::ifstream(filename.c_str(), std::ifstream::in);

  std::ofstream *writer = new std::ofstream("file.packed");
  
  char ch;
  while(infile->get(ch)){


    for(int chCount = Dictionary[(int)ch]->Depth-1; chCount >=0; chCount--){

      if(byteLength == 8){


      writeBuffer = &buffer;

      writeChar(writeBuffer,writer);

      buffer = 0;
      byteLength = 0;

      }
      

      if(((Dictionary[(int)ch]->BiPath)>>(chCount)&1) == 1){

      buffer = buffer|(1<<(7-byteLength));
      }else{

      }

      byteLength++;
      
    }
    WriteCount++;
  }
  
  *writeBuffer = buffer;
  writeChar(writeBuffer,writer); 

  infile->close();
  writer->close();
}


void Writer::writeChar(char *byte, std::ofstream *writer){

writer->write(byte,1);




}




