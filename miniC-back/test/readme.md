g++ -g -std=gnu++11 -Wno-deprecated *.cpp -o test/miniC
cp test/miniC /var/www/html/miniC/
cp test/miniC /usr/bin/

miniC -s hello.c -o assemble.s

gcc -o hello.exe assemble.s

gcc -masm=intel -m32 -S hello.c -o ass.s

-masm=intel -m32

-l sourceFile.c
        standard output the result of lexical analysis
-l sourceFile.c -o lexfile.l
        output the result of lexical analysis to lexFile.l
-p sourceFile.c
        standard output the Parsing processing
-p sourceFile.c -o parsefile.p
        output the Paring processing to parsefile.p
-i sourceFile.c
        standard output the intermediate code
-i sourceFile.c -o intercode.ic
        output the intermediate code to intercode.ic
-s sourceFile.c
        output the generated assembly language file to assemble.s
-s sourceFile.c -o assembleFile.s[DEFAULT]
        output the generated assembly language file to assembleFile.s
        DEFAULT  means a given name by system
-c assemble.s -o test
        using assembly code assemble.s to generate executable program to test
-exit
        to exit the processing
-help
        introduction to the instruction set