#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "saveBooks.h"
#include "search.h"

void returnBook(Bib *books);
void actualReturnBook(Bib *books, book *book);

#endif
