#include "showAll.h"

void showAll(Bib *bib)
{
    foundBooks foundBooks;
    char searchString[] = "";
    search(bib, &foundBooks, searchString);

    showFoundBooks(&foundBooks, "itanb");

    int chosenBook = 0;
    int isNotAborted;
    chooseBook(&foundBooks, &chosenBook, &isNotAborted);
    chosenBook--;
    contextBookAction(bib, foundBooks.books[chosenBook], chosenBook);
    freeFoundBooks(&foundBooks);
}
