#include "search.h"
/*
 *  function: search
 *      searches for books with given searchString and adds them to foundBooksArray
 *  params:
 *      Array *books        (pointer to books structure)
 *      foundBooks *foundBooks      (pointer to array of book pointers)
 *      char *searchString  (pointer to string to search for)
*/
void search(Array *books, foundBooks *foundBooks, char *searchString)
{
    // TODO: if searched with isbn-13: 978-3-86680-192-9 strip out the hyphen
    // initialize the array where the book pointers will be stored
    foundBooks->array = malloc(0);

    // replace umlauts of searchstring with corresponding chars (�=>-124, �=>-127, �=>-108, �=>-31)
    searchString = replaceUmlauts(searchString);

    // make the searchString to lower case, so the comparison is case insensitive
    stringToLower(searchString);

    // iterate over array of books and add pointer to PointerArray "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<books->used; i++){
        // make the author and the title to lower case, so the comparison is case insensitive
        char author[strlen(books->array[i].author)+1];
        char title[strlen(books->array[i].title)+1];
        strcpy(author, books->array[i].author);
        strcpy(title, books->array[i].title);
        stringToLower(author);
        stringToLower(title);

        // check if searchString matches any of isbn, author or title of the current book
        if(strstr(books->array[i].isbn, searchString) != NULL || strstr(author, searchString) != NULL || strstr(title, searchString) != NULL){
            // adding the pointer to this book to the foundBooks array
            foundBooks->array = (book *) realloc(foundBooks->array, (index+1)*sizeof(book *));
            foundBooks->array[index] = &books->array[i];
            index++;
        }
    }
    // write the number of found elements to the size attribute of the foundBooks structure
    foundBooks->size = index;

    // output if no books were found
    if(foundBooks->size == 0){
        printf("ERROR: Keine B%ccher mit '%s' gefunden!\n", ue, searchString);
    }
}

void chooseBook(char *userNumber, foundBooks *foundBooks, int *chosenBook, int *isNotAborted)
{
    do{
        printf("Buch w%chlen [NUMMER] ([ENTER] zum Abbrechen): ", ae);
        getUserInput(userNumber);
        *chosenBook = atoi(userNumber);

        // if number out of index was chosen
        if(*chosenBook<=0 || *chosenBook>foundBooks->size){
            printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
        }

        // check for Abortion through user (pressed ENTER)
        *isNotAborted = !isAborted(userNumber);

        printf("isNotAborted: %d\n", *isNotAborted);

//            } while((chosenBook<=0 || chosenBook>foundBooks.size) && chosenBook != '\0');
    } while(*isNotAborted && (*chosenBook<=0 || *chosenBook>foundBooks->size));
}
