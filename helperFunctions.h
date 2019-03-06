#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"

#define BUFFERSIZE 512
#define HEADERTABSIZE 6
#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225

//void getUserInput(char *userVariable, const char message[]);
void getUserInput(char *userVariable);
int isAborted(char *userVariable);
void printMenuHeader(char *header);
void printMenuEnding(int menuHeaderLength);
void showReturnToMenu();
void freeTempString(char *var);

#endif
