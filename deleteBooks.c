#include "deleteBooks.h"

void deleteBooks(Array *books)
{
    char *searchString = calloc(1, 1);
    printf("Welches Buch soll gel%cscht werden? (Titel, Autor, ISBN) ([ENTER] zum Abbrechen): ", oe);
    getUserInput(searchString);
    if(!isAborted(searchString)){
        foundBooks foundBooks;
        search(books, &foundBooks, searchString);

        // let the user choose a book
        int chosenBook = 0;
        char *userNumber = calloc(1,1);
        int isNotAborted;
        chooseBook(userNumber, &foundBooks, &chosenBook, &isNotAborted);
    }
}

void actualDeleteBooks(Array *books, book *book)
{

    saveBooks(books);
}
