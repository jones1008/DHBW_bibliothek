#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"

#define BUFFERSIZE 256
#define HEADERTABSIZE 6

#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225

void getUserInput(char *userVariable);
int wrongCharInput(char *userInput, char *allowedChars);
int isAborted(char *userVariable);

//char *trimWhitespace(char *str);
char *trim(char *str);
//size_t trimWhitespace(char *out, size_t len, const char *str);
char *replaceUmlauts(char *str);
void stringToLower(char *strPtr);
int countChars(char* str, char c);
void removeChar(char *str, int c);

void printMenuHeader(char *header);
void printMenuEnd(char *end);
//void printMenuEnding(int menuHeaderLength);

void freeTempString(char *var);
void freeFoundBooks(foundBooks *foundBooks);

#endif
