#include "borrowBook.h"
void borrowBook(Array *books)
{
    char searchString[BUFFERSIZE];
    printf("Welches Buch soll ausgeliehen werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ");
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);
        showFoundBooks(&foundBooks, "ati");

        // let the user choose a book
        int chosenBook = 0;
        int isNotAborted;
        chooseBook(&foundBooks, &chosenBook, &isNotAborted);
        if(isNotAborted){
            // TODO: rausfinden, wie man hier auf das gewählte Buch kommt (PointerPointer)
            printf("chosenBook: %d\n", chosenBook);
//            printf("chosenbook isbn: %d\n", *foundBooks.array[chosenBook]);


//            printf("pointer to chosenBook: %s\n", foundBooks.array[chosenBook]->author);
//            actualDeleteBooks(books, &foundBooks.array[chosenBook]);
        }
    }
}

void actualBorrowBook(Array *books, book *book)
{

    saveBooks(books);
}
