#ifndef DELETEBOOKS_H
#define DELETEBOOKS_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "helperFunctions.h"
#include "search.h"

void deleteBooks(Array *books);
void actualDeleteBooks(Array *books, book **book);

#endif
