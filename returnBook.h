#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "saveBooks.h"
#include "search.h"

//typedef struct{
//    char *ptr;
//} borrower;
//typedef struct{
//    borrower *borrowers;
//    size_t size;
//} foundBorrowers;

void returnBook(Bib *bib);
void actualReturnBook(Bib *bib, book *book, int chosenBook);
//void newBorrower(foundBorrowers *foundBorrowers);

#endif
