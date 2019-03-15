#include "searchBooks.h"

// TODO: stürzt ab, wenn zweimal hintereinander in der Suche ein Leerzeichen eingegeben wurde: Lösung:? wenn nur Leerzeichen, dann Fehlermeldung, dass nichts eingegeben wurde
void searchBooks(Bib *bib)
{
    // TODO: automatically chose first one, if only one ergebnis
    // get user search input
//    char *searchString = malloc(0);
    char searchString[BUFFERSIZE];

//    getUserInput(searchString, "Suchtext ([ENTER] zum Abbrechen): ");
    printf("Suchtext ([ENTER] zum Abbrechen): ");
    getUserInput(searchString);

//    printf("searchString: %s\n", searchString);
//    printf("searchStringD: %d\n", searchString[0]);

    // check if the input was aborted
//    printf("isAborted: %d\n", isAborted(searchString));
    if(!isAborted(searchString)){
//        printf("is not aborted!\n");
        // pass searchString to the search-function
        foundBooks foundBooks;
//        printf("vor search: book->numberof: %s\n", bib->books[5].numberof);
//        printf("before search\n");
        search(bib, &foundBooks, searchString);
//        printf("searchBooks: nach dem Suchen: book->author: %s\n", foundBooks.books[0]->numberof);

        if(foundBooks.size != 0){
            showFoundBooks(&foundBooks, "atinb");
            if(foundBooks.size>1){
                int chosenBook = 0;
                int isNotAborted;
                chooseBook(&foundBooks, &chosenBook, &isNotAborted);
                if(isNotAborted){
                    chosenBook--;
                    // write book and free foundBooks before other function is called
                    book *book = foundBooks.books[chosenBook];
                    freeFoundBooks(&foundBooks);
                    // run context-action for the foundBooks
                    contextBookAction(bib, book, chosenBook);
                }
            } else if(foundBooks.size == 1){
                // write book and free foundBooks before other function is called
                book *book = foundBooks.books[0];
                freeFoundBooks(&foundBooks);
                contextBookAction(bib, book, 1);
            } else{
                freeFoundBooks(&foundBooks);
            }
        } else{
//            printf("no results: before freefoundBooks\n");
            freeFoundBooks(&foundBooks);
//            printf("no results: before searchBooks\n");
            searchBooks(bib);
        }
//        freeFoundBooks(&foundBooks);
    }
//    printf("end of searchBooks()\n");
}

// TODO: evtl in search.c platzieren? macht mehr Sinn?
void contextBookAction(Bib *bib, book *book, int chosenBook)
{
    // let the user choose a book to borrow/return/delete/addCopy the chosen book
    printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook, book->author, book->title);

    // when a number was chosen: ask user what he wants to do with that book
//    if(isNotAborted) {
//        printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook, foundBooks->books[chosenBook-1]->author, foundBooks->books[chosenBook-1]->title);

        char *allowedChars = "azlc";
        char userChar[BUFFERSIZE];
        int isNotAborted;

        printf("[A]: Buch ausleihen\n");
        printf("[Z]: Buch zur%cckgeben\n", ue);
        printf("[L]: Buch l%cschen\n", oe);
        printf("[C]: Buchexemplar hinzuf%cgen\n", ue);

        // repeat user input if the input was wrong or not Aborted
        do{
            // get user input and write tolower-variable so comparison is
            printf("Aktion w%chlen ([ENTER] zum Abbrechen): ", ae);
            getUserInput(userChar);
            *userChar = tolower(*userChar);

            // check for Abortion through user (pressed ENTER)
            isNotAborted = !isAborted(userChar);

        } while(isNotAborted && wrongCharInput(userChar, allowedChars));

        // if user chose a number and did not hit ENTER
        if(isNotAborted){
            printf("\n");
            // run the corresponding function with a pointer to the chosen book
            // TODO: add feedback to the user that the action was performed
            char menuHeader[BUFFERSIZE] = "";
            switch(userChar[0]){
                case 'a':
                    strcpy(menuHeader, "BUCH AUSLEIHEN");
                    printMenuHeader(menuHeader);
                    actualBorrowBook(bib, book, chosenBook);
                    break;
                case 'z':
                    strcpy(menuHeader, "BUCH ZURUECKGEBEN");
                    printMenuHeader(menuHeader);
                    actualReturnBook(bib, book, chosenBook);
                    break;
                case 'l':
                    strcpy(menuHeader, "BUCH LOESCHEN");
                    printMenuHeader(menuHeader);
                    actualDeleteBooks(bib, book, chosenBook);
                    break;
                case 'c':
                    // TODO: ein oder ausbauen!
                    strcpy(menuHeader, "BUCHEXEMPLAR HINZUFUEGEN");
                    printMenuHeader(menuHeader);
//                    actualAddCopies(bib, book, chosenBook);
                    break;
                default:
                    printf("Falsche Eingabe!\n");
                    break;
            }
            stringToLower(menuHeader);
            printMenuEnd(menuHeader);
//            printf("\n");
        }
//    }
}
