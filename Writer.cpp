#include"Writer.h"
#include <bitset>
#include <cstdlib>
void Writer::Translate(ListNode *Dictionary[], std::string filename){
  char buffer = 0;
  int byteLength = 0;
  char *writeBuffer;
  
  std::ifstream *infile = new std::ifstream(filename.c_str(), std::ifstream::in);

  std::ofstream *writer = new std::ofstream("file.packed");
  
  char ch;
  while(infile->get(ch)){

    std::bitset<8>currByte(buffer);
    std::cout << "The current byte looks like:" << currByte << std::endl;

    std::cout << std::endl << "The current char is " << ch << std::endl;
    for(int chCount = Dictionary[(int)ch]->Depth-1; chCount >=0; chCount--){

      if(byteLength == 8){

      std::bitset<8>writeByte(buffer);

      *writeBuffer = buffer;
      writeChar(writeBuffer,writer);

      buffer = 0;
      byteLength = 0;
      std::cout << std::endl << "A Byte was written to file." << std::endl;
      std::cout << writeByte << std::endl;

      }
      
      std::cout << std::endl << "The shift is currently " << chCount << std::endl;  
      std::cout << std::endl << "The Depth of this char is " << Dictionary[(int)ch]->Depth << std::endl;
      std::cout << "The Length is " << byteLength << std::endl; 

      std::bitset<8> byte(buffer);
      std::cout << "The byte inside the loop looks like: " <<  byte << std::endl;
      std::cout << std::endl << "The shift on the byte is " << 7-byteLength << std::endl;

      if(((Dictionary[(int)ch]->BiPath)>>(chCount)&1) == 1){

      buffer = buffer|(1<<(7-byteLength));
      std::cout << std::endl << "A bit was written to the buffer" << std::endl;
      }else{
      std::cout <<std::endl << "No bit was written to the buffer" << std::endl;

      }

      byteLength++;
    }
  }
  
  *writeBuffer = buffer;
  writeChar(writeBuffer,writer); 

  infile->close();
  writer->close();
}


void Writer::writeChar(char *byte, std::ofstream *writer){

writer->write(byte,1);




}




