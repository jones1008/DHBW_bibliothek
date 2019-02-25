#ifndef SAVEBOOKS_H
#define SAVEBOOKS_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"

void strreplace(char s[], char chr, char repl_chr);
char *replaceUmlauts(char* string);
void saveBooks(Array *books);

#endif
