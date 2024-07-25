#include <stdio.h>
#include <stdbool.h>


#include "../include/common.h"
#include "../include/compiler.h"
#include "../include/scanner.h"


void compile(const char* source)
{
    initScanner(source);
    int line = -1;
    for(;;)
    {
        Token token = scanToken();
        if(token.line != line)
        {
            printf("%4d ", token.line);
            line = token.line;
        }
        else
        {
            printf("   | ");
        }
        printf("%2d '%.*s'\n", token.type, token.length, token.start);
        if(token.type == TOKEN_EOF) break;
    }
}