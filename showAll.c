#include "showAll.h"

void showAll(Bib *bib)
{
    foundBooks foundBooks;
    char searchString[] = "";
    search(bib, &foundBooks, searchString);

    showFoundBooks(&foundBooks, "itanb");

    contextBookAction(bib, &foundBooks);
    freeFoundBooks(&foundBooks);
}
