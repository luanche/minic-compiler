#include <iostream>
#include "global.h"
#include <string.h>
#include "Parser.h"
#include <iomanip>
#include <stdio.h>
//#include <windows.h>
#include <fstream>
#include <unistd.h>
using namespace std;

int main(int args, char **argv)
{

    if (args == 1)
    {
        cout << "no input files compilation terminated" << endl;
        exit(0);
    }
    else if (args == 2)
    {
        if (strcmp(argv[1], "-exit") == 0)
            exit(0);
        else if (strcmp(argv[1], "-help") == 0)
        {

            highlight("-l ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight("\n\t standard output the result of lexical analysis", EXPLANATION);
            cout << endl;
            highlight("-l ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight(" -o ", KEYWORDS);
            highlight("lexfile.l", PARAMETER);
            highlight("\n\t output the result of lexical analysis to lexFile.l", EXPLANATION);
            cout << endl;

            highlight("-p ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight("\n\t standard output the Parsing processing", EXPLANATION);
            cout << endl;
            highlight("-p ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight(" -o ", KEYWORDS);
            highlight("parsefile.p", PARAMETER);
            highlight("\n\t output the Paring processing to parsefile.p", EXPLANATION);
            cout << endl;

            highlight("-i ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight("\n\t standard output the intermediate code", EXPLANATION);
            cout << endl;
            highlight("-i ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight(" -o ", KEYWORDS);
            highlight("intercode.ic", PARAMETER);
            highlight("\n\t output the intermediate code to intercode.ic", EXPLANATION);
            cout << endl;
            highlight("-s ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight("\n\t output the generated assembly language file to assemble.s", EXPLANATION);
            cout << endl;
            highlight("-s ", KEYWORDS);
            highlight("sourceFile.c", PARAMETER);
            highlight(" -o ", KEYWORDS);
            highlight("assembleFile.s[DEFAULT]", PARAMETER);
            highlight("\n\t output the generated assembly language file to assembleFile.s", EXPLANATION);
            highlight("\n\t DEFAULT  means a given name by system", EXPLANATION);
            cout << endl;
            highlight("-c ", KEYWORDS);
            highlight("assemle.s", PARAMETER);
            highlight(" -o ", KEYWORDS);
            highlight("test", PARAMETER);
            highlight("\n\t using assembly code assemble.s to generate executable program to test", EXPLANATION);
            cout << endl;
            //cout<<"-lex sourceFile.c -o lexfile.txt\n\t output the result of lexical analysis to lexFile.txt"<<endl;
            //cout<<"-parse sourceFile.c\n\t standard output the Parsing processing"<<endl;
            //cout<<"-parse sourceFile.c -o parse.txt\n\t output the Paring processing to lexFile.txt"<<endl;
            // cout<<"-intercode sourceFile.c\n\t standard output the intermediate code" <<endl;
            //cout<<"-intercode sourceFile.c -o intercode.txt\n\t output the intermediate code to intercode.txt"<<endl;
            //cout<<"-S sourceFile.c -o assembleFile.asm\n\t output the generated assembly language file to assembleFile.asm"<<endl;
            highlight("-exit ", KEYWORDS);
            highlight("\n\t to exit the processing", EXPLANATION);
            cout << endl;
            highlight("-help ", KEYWORDS);
            highlight("\n\t introduction to the instruction set", EXPLANATION);
            //cout<<"-exit\n\t to exit the processing"<<endl;
            //cout<<"-help\n\t introduction to the instruction set"<<endl;
            highlight("\n", NORMAL);
        }
        else
        {
            cout << "Unavailable instructions" << endl;
            exit(0);
        }
    }
    else if (args == 3)
    {
        if (strcmp(argv[1], "-l") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            //cout<<filename<<endl;
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            lex = new Lex(filename);
            lex->analysis();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            lex->LexShow();
        }
        else if (strcmp(argv[1], "-p") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            Parser *parser = new Parser(filename);
            parser->analyze();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            parser->DrawTree();
        }
        else if (strcmp(argv[1], "-i") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            Parser *parser = new Parser(filename);
            parser->analyze();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            symtab->ShowIR();
        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            Parser *parser = new Parser(filename);
            parser->analyze();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            targetFile = (char *)malloc(100);
            strcpy(targetFile, "assemble.s");
            if (!(file = fopen(targetFile, "w")))
            {
                cout << "File redirect failed" << endl;
                exit(0);
            }
            symtab->genAsm();
        }
        else
        {
            cout << "Unavailable instructions" << endl;
            exit(0);
        }
    }
    else if (args == 5 && ((strcmp(argv[3], "-o") == 0) || (strcmp(argv[3], ">") == 0)))
    {
        if (strcmp(argv[1], "-l") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            lexFile = (char *)malloc(100);
            strcpy(lexFile, argv[4]);
            lex = new Lex(filename);
            lex->analysis();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            lex->LexShow(true);
        }
        else if (strcmp(argv[1], "-p") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            Parser *parser = new Parser(filename);
            parser->analyze();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            parseFile = (char *)malloc(100);
            strcpy(parseFile, argv[4]);
            parser->DrawTree(true);
        }
        else if (strcmp(argv[1], "-i") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            Parser *parser = new Parser(filename);
            parser->analyze();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            intercodeFile = (char *)malloc(100);
            strcpy(intercodeFile, argv[4]);
            symtab->ShowIR(true);
        }
        else if (strcmp(argv[1], "-s") == 0)
        {
            filename = (char *)malloc(100);
            strcpy(filename, argv[2]);
            if (!(source = fopen(filename, "r+")))
            {
                cout << "No such file or dictionary!" << endl;
                exit(0);
            }
            Parser *parser = new Parser(filename);
            parser->analyze();
            if (errorNum > 0)
            {
                cout << "\t=== Build finished: " << errorNum << " error(s), " << warnNum << " warning(s) ===" << endl;
                exit(0);
            }
            cout << "\t=== Build finished: 0 error(s), " << warnNum << " warning(s) ===" << endl;
            if (strcmp(argv[4], "DEFAULT") == 0)
            {
                targetFile = strcat(lex->getFileName(false), ".s");
            }
            else
            {
                targetFile = (char *)malloc(100);
                strcpy(targetFile, argv[4]);
            }
            if ((file = fopen(targetFile, "w")) == NULL)
            {
                cout << "cannot create the file" << endl;
                exit(0);
            }
            symtab->genAsm();
        }
        else if (strcmp(argv[1], "-c") == 0)
        {
            char * exe_argv[]={"gcc","-m32",argv[2],"-o",argv[4],NULL};
            if(vfork() == 0)
            {
            execv("/usr/bin/gcc",exe_argv);
            }
        }
        else
        {
            cout << "Unavailable instructions" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "Wrong instruction format!" << endl;
    }
}
