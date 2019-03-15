#include "showAll.h"

/*
 *  function:
 *
 *  params:
 *
 */
void showAll(Bib *bib)
{
    foundBooks foundBooks;
    char searchString[] = "";
    search(bib, &foundBooks, searchString);

    showFoundBooks(&foundBooks, "itanb");

    int chosenBook = 0;
    int isNotAborted;
    chooseBook(&foundBooks, &chosenBook, &isNotAborted);
    if(isNotAborted){
//        printf("before minus\n");
        chosenBook--;
//        printf("chosenBook: %s\n", chosenBook);

        book *book = foundBooks.books[chosenBook];
        freeFoundBooks(&foundBooks);

        contextBookAction(bib, book, chosenBook);
//        printf("after contextBookAction\n");
    } else{
        freeFoundBooks(&foundBooks);
    }
}
