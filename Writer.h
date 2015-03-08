#ifndef WRITE_H_
#define WRITE_H_
#include<fstream>

#include"Tree.h"

class Writer{
private:

public:


Writer() { }

char getByte();
void writeChar(char *byte, std::ofstream *writer);
void Translate(ListNode *Dictionary[],std::string filename, long &WriteCount);




};

#endif
