#ifndef SCANNER_H
#define SCANNER_H
#include <stdio.h>
#define BUFLEN 200
#include "global.h"
#include <string>
using namespace std;
class Scanner
{
public:
    char scan(FILE *file);
    int getLine();
    int getCol();
    int bufferLen = 0;
    int readPos = -1;
    char buffer[BUFLEN];
    int lineNum = 1; //行
    int colNum = 0;  //列
    int lastCol = 0;
    char lastch;

protected:
private:
};

#endif // SCANNER_H
