#include "addCopies.h"
void addCopies(Bib *bib)
{
//    char searchString[BUFFERSIZE];
//    printf("Zu welchem Buch sollen Exemplare hinzugef%cgt werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", ue);
//    getUserInput(searchString);
//    if(!isAborted(searchString)){
//        foundBooks foundBooks;
//        search(bib, &foundBooks, searchString);
//        showFoundBooks(&foundBooks, "atin");
//
//        // let the user choose a book
//        int chosenBook = 0;
//        int isNotAborted;
//        chooseBook(&foundBooks, &chosenBook, &isNotAborted);
//        if(isNotAborted){
//            // TODO: rausfinden, wie man hier auf das gewählte Buch kommt (PointerPointer)
//            printf("chosenBook: %d\n", chosenBook);
////            printf("chosenbook isbn: %d\n", *foundBooks.array[chosenBook]);
//
//
////            printf("pointer to chosenBook: %s\n", foundBooks.array[chosenBook]->author);
////            actualDeleteBooks(bib, &foundBooks.array[chosenBook]);
//        }
//    }
}

void actualAddCopies(Bib *bib, book *book)
{

    saveBooks(bib);
}
