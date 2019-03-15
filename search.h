#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "helperFunctions.h"
#include "borrowBook.h"
#include "deleteBooks.h"
#include "returnBook.h"

void search(Bib *bib, foundBooks *foundBooks, char *searchString);
void showFoundBooks(foundBooks *foundBooks, char *attributes);
void chooseBook(foundBooks *foundBooks, int *chosenBook, int *isNotAborted);
void showChosenBook(int chosenBook, book *book);
void contextBookAction(Bib *bib, book *book, int chosenBook);

#endif
