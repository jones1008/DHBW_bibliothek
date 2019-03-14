#include "search.h"
/*
 *  function: search
 *      searches for books with given searchString and adds them to foundBooksArray
 *  params:
 *      Bib *bib        (pointer to bib structure)
 *      foundBooks *foundBooks      (pointer to array of book pointers)
 *      char *searchString  (pointer to string to search for)
*/
void search(Bib *bib, foundBooks *foundBooks, char *searchString)
{
    printf("search: searchString: %s\n", searchString);
    // TODO: if searched with isbn-13: 978-3-86680-192-9 strip out the hyphen
    // initialize the array where the book pointers will be stored
    foundBooks->array = malloc(0);

    // replace umlauts of searchstring with corresponding chars (ä=>-124, ü=>-127, ö=>-108, ß=>-31)

//    printf("search: before replaceUmlauts\n");
    searchString = replaceUmlauts(searchString);
//    printf("search: after replaceUmlauts\n");

    // make the searchString to lower case, so the comparison is case insensitive
//    printf("search: before strToLower\n");
    stringToLower(searchString);
//    printf("search: after strToLower\n");

    // iterate over array of bib and add pointer to PointerBib "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<bib->used; i++){
        // make the author and the title to lower case, so the comparison is case insensitive
        char author[strlen(bib->array[i].author)+1];
        char title[strlen(bib->array[i].title)+1];
        strcpy(author, bib->array[i].author);
        strcpy(title, bib->array[i].title);
        stringToLower(author);
        stringToLower(title);

        // check if searchString matches any of isbn, author or title of the current book
        if(strstr(bib->array[i].isbn, searchString) != NULL || strstr(author, searchString) != NULL || strstr(title, searchString) != NULL){
            // adding the pointer to this book to the foundBooks array
            foundBooks->array = realloc(foundBooks->array, (index+1)*sizeof(book *));
//            foundBooks->array = (book *) realloc(foundBooks->array, (index+1)*sizeof(book *));
            // TODO: wird hier tatsächlich der Richtige Pointer hinzugefügt? hat nicht die gleiche Adresse, wie hinterher in deleteBooks() (evtl in struct ein * weglassen?)
            foundBooks->array[index] = &bib->array[i];
//            printf("pointer to book: %d\n", &bib->array[i]);
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
// for each found book in foundbooks print the given attributes in order
void showFoundBooks(foundBooks *foundBooks, char attributes[])
{
    printf("\n");
    for(int i=0; i<foundBooks->size; i++){
        printf("[%d]\n", i+1);
        // loop over attributes to print attributes in correct order
        for(int j=0; j<strlen(attributes); j++){
            switch(attributes[j]){
                case 'a':
                    printf("Autor    : %s\n", foundBooks->array[i]->author);
                    break;
                case 't':
                    printf("Titel    : %s\n", foundBooks->array[i]->title);
                    break;
                case 'i':
                    printf("ISBN     : %s\n", foundBooks->array[i]->isbn);
                    break;
                case 'n':
                    printf("Anzahl   : %s\n", foundBooks->array[i]->numberof);
                    break;
                case 'b':
                    printf("Ausleiher: %s\n", foundBooks->array[i]->borrowlist);
                    break;
                default:
                    printf("ERROR: unbekanntes Attribut!\n");
            }
        }
        // add Line if it isn't the last found book
        if(i+1<foundBooks->size){
            printf("---------\n");
        }
    }
    printf("\n");
}

void chooseBook(foundBooks *foundBooks, int *chosenBook, int *isNotAborted)
{
    char userNumber[BUFFERSIZE];
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

//        printf("isNotAborted: %d\n", *isNotAborted);

//            } while((chosenBook<=0 || chosenBook>foundBooks.size) && chosenBook != '\0');
    } while(*isNotAborted && (*chosenBook<=0 || *chosenBook>foundBooks->size));
}
