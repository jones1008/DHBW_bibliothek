#include "showAll.h"

void showAll(Bib *books)
{
    foundBooks foundBooks;
    char searchString[] = "";
    search(books, &foundBooks, searchString);

    showFoundBooks(&foundBooks, "itanb");

    contextBookAction(books, &foundBooks);
}
