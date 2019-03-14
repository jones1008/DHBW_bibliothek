#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <stddef.h>

// define book-structure inside of array
typedef struct
{
    char* title;
    char* isbn;
    char* author;
    char* numberof;
    char* borrowlist;
} book;
typedef struct
{
    book *books;
    size_t used;
    size_t size;
} Bib;

// TODO: direkt auf das Buch pointern (normaler Pointer)
typedef struct{
    book **books;
    size_t size;
} foundBooks;

void writeStringToArrayNode(Bib *bib, char node, char *string);
void newBook(Bib *bib);

#endif
