#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <stddef.h>

// defines a book structure with all it's attributes
typedef struct
{
    char* title;
    char* isbn;
    char* author;
    char* numberof;
    char* borrowlist;
} book;
// defines the Bibliothek-wrapper-structure with a pointer to the books and information about size and used
typedef struct
{
    book *books;
    size_t used;
    size_t size;
} Bib;

// defines the foundBooks structure with a pointer pointer to the books and the size
typedef struct{
    book **books;
    size_t size;
} foundBooks;

void writeStringToArrayNode(Bib *bib, char node, char *string);
void newBook(Bib *bib);

#endif
