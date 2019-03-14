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
        // pass searchString to the search-function
        foundBooks foundBooks;
//        printf("vor search: book->numberof: %s\n", bib->books[5].numberof);
        search(bib, &foundBooks, searchString);
//        printf("searchBooks: nach dem Suchen: book->author: %s\n", foundBooks.books[0]->numberof);

        if(foundBooks.size > 0){
            showFoundBooks(&foundBooks, "atinb");
            // run context-action for the foundBooks
            contextBookAction(bib, &foundBooks);
        } else{
            searchBooks(bib);
        }
        freeFoundBooks(&foundBooks);
    }
}

void contextBookAction(Bib *bib, foundBooks *foundBooks)
{
    // let the user choose a book to borrow/return/delete/addCopy the chosen book
    int chosenBook = 0;
    int isNotAborted;
    chooseBook(foundBooks, &chosenBook, &isNotAborted);

    // when a number was chosen: ask user what he wants to do with that book
    if(isNotAborted) {
        printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook, foundBooks->books[chosenBook-1]->author, foundBooks->books[chosenBook-1]->title);

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
            switch(userChar[0]){
                case 'a':
//                    actualBorrowBook(bib, foundBooks->books[chosenBook-1]);
                    break;
                case 'z':
//                    actualReturnBook(bib, foundBooks->books[chosenBook-1]);
                    break;
                case 'l':
//                    actualDeleteBooks(bib, foundBooks->books[chosenBook-1]);
                    break;
                case 'c':
//                    actualAddCopies(bib, foundBooks->books[chosenBook-1]);
                    break;
                default:
                    printf("Falsche Eingabe!\n");
                    break;
            }
        }
    }
}
