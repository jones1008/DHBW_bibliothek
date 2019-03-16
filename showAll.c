#include "showAll.h"

/*
 *  function:
 *      Shows all books in the bib structure, lets the user choose one and shows available context actions.
 *  params:
 *      Bib *bib
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
