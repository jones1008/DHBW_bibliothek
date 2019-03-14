#ifndef ADDCOPIES_H
#define ADDCOPIES_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "saveBooks.h"

void addCopies(Bib *books);
void actualAddCopies(Bib *books, book *book);

#endif
