#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "helperFunctions.h"
#include "searchBooks.h"

void search(Array *books, foundBooks *foundBooks, char *searchString);
void chooseBook(char *userNumber, foundBooks *foundBooks, int *chosenBook, int *isNotAborted);

#endif
