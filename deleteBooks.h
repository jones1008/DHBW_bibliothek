#ifndef DELETEBOOKS_H
#define DELETEBOOKS_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "helperFunctions.h"
#include "saveBooks.h"
#include "search.h"

void deleteBooks(Bib *bib);
void actualDeleteBooks(Bib *bib, book *book, int chosenBook);

#endif
