#ifndef BORROWBOOK_H
#define BORROWBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "saveBooks.h"
#include "search.h"

void borrowBook(Bib *bib);
void actualBorrowBook(Bib *bib, book *book);

#endif
