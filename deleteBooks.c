#include "deleteBooks.h"



void deleteBooks(Array *books)
{
    char bookTitle [80];
    //which book shall be deleted?
    printf("Welches Buch soll gelöscht werden?\n");
    fgets(bookTitle, 80, stdin);
   // hier mit suchstring verknüpfen


}

void actualDeleteBooks(Array *books, book *book)
{

    saveBooks(books);
}
