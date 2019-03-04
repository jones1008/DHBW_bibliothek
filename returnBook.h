#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "structure.h"
#include "saveBooks.h"

void returnBook(Array *books);
void actualReturnBook(Array *books, book *book);

#endif
