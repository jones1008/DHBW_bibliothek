#include "search.h"

/*
 *  function: search
 *      Searches for books with given searchString and adds them to the foundBooks structure.
 *  params:
 *      Bib *bib (pointer to bib structure)
 *      foundBooks *foundBooks (pointer to array of book pointers)
 *      char *searchString (pointer to string to search for)
*/
void search(Bib *bib, foundBooks *foundBooks, char *searchString)
{
    // initialize the array where the book pointers will be stored
    foundBooks->books = malloc(0);

    // replace umlauts and make searchString lowercased, so comparison is case insensitive
    replaceUmlauts(searchString);
    stringToLower(searchString);

    // iterate over array of bib and add pointer to PointerBib "foundBooks" if isbn, author or title matches the given SearchString
    int index = 0;
    for(int i=0; i<bib->used; i++){
        // skip book if all of its attributes is NULL
        if(!(bib->books[i].isbn == NULL && bib->books[i].title == NULL && bib->books[i].author == NULL && bib->books[i].numberof == NULL && bib->books[i].borrowlist == NULL)){
            // make the author and the title to lower case, so the comparison is case insensitive
            char author[strlen(bib->books[i].author)+1];
            char title[strlen(bib->books[i].title)+1];
            strcpy(author, bib->books[i].author);
            strcpy(title, bib->books[i].title);
            stringToLower(author);
            stringToLower(title);

            // check if searchString matches any of isbn, author or title of the current book
            if(strstr(bib->books[i].isbn, searchString) != NULL || strstr(author, searchString) != NULL || strstr(title, searchString) != NULL){
                // adding the pointer to this book to the foundBooks array
                foundBooks->books = realloc(foundBooks->books, (index+1)*sizeof(book *));
                foundBooks->books[index] = &bib->books[i];
                index++;
            }
        }
    }
    // write the number of found elements to the size attribute of the foundBooks structure
    foundBooks->size = index;

    // output if no books were found
    if(foundBooks->size == 0){
        printf("ERROR: Keine B%ccher mit '%s' gefunden!\n", ue, searchString);
    }
}

/*
 *  function:
 *      Loops over the found books structure and prints the given attributes from every book in foundBooks.
 *  params:
 *      foundBooks *foundBooks (pointer to the foundBooks structure)
 *      char attributes[] (char array of abbreviations for the attributes to print)
 */
void showFoundBooks(foundBooks *foundBooks, char attributes[])
{
    if(foundBooks->size>0){
        printf("\n");
    }
    for(int i=0; i<foundBooks->size; i++){
        printf("[%d]\n", i+1);
        // loop over attributes to print attributes in correct order
        for(int j=0; j<strlen(attributes); j++){
            switch(attributes[j]){
                case 'a':
                    printf("Autor    : %s\n", foundBooks->books[i]->author);
                    break;
                case 't':
                    printf("Titel    : %s\n", foundBooks->books[i]->title);
                    break;
                case 'i':
                    printf("ISBN     : %s\n", foundBooks->books[i]->isbn);
                    break;
                case 'n':
                    printf("Anzahl   : %s\n", foundBooks->books[i]->numberof);
                    break;
                case 'b':
                    printf("Ausleiher: %s\n", foundBooks->books[i]->borrowlist);
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
    if(foundBooks->size>0){
        printf("\n");
    }
}

/*
 *  function:
 *      Lets the user choose a book of the foundBooks and prints error messages, if a wrong input was made.
 *  params:
 *      foundBooks *foundBooks (pointer to the foundBooks structure)
 *      int chosenBook (this is where the chosenBook index is stored)
 *      int *isNotAborted (int pointer to basically a bool value if the process was aborted by the user or not (ENTER))
 */
void chooseBook(foundBooks *foundBooks, int *chosenBook, int *isNotAborted)
{
    char userNumber[BUFFERSIZE];
    do{
        printf("Buch w%chlen [NUMMER] ([ENTER] zum Abbrechen): ", ae);
        getUserInput(userNumber);
        *chosenBook = atoi(userNumber);

        // check for Abortion through user (pressed ENTER)
        *isNotAborted = !isAborted(userNumber);

        // if number out of index was chosen
        if(*isNotAborted && (*chosenBook<=0 || *chosenBook>foundBooks->size)){
            printf("ERROR: Falsche Eingabe oder eingegebene Zahl au%cerhalb des Index!\n", ss);
        }
    } while(*isNotAborted && (*chosenBook<=0 || *chosenBook>foundBooks->size));
}

/*
 *  function:
 *      Shows a brief summary to the user which book was chosen.
 *  params:
 *      int chosenBook (integer value of the chosen book)
 *      book *book (pointer to the chosen book)
 */
void showChosenBook(int chosenBook, book *book)
{
    printf("---> gew%chltes Buch: [%d] - %s - %s\n", ae, chosenBook+1, book->author, book->title);
}

/*
 *  function:
 *      Shows the context actions "borrow", "return" and "delete" for the chosen book. Calls the corresponding function of the chosen action.
 *  params:
 *      Bib *bib
 *      book *book (a pointer to the chosen book)
 *      int chosenBook (the index of the chosen book in the foundBooks structure)
 */
void contextBookAction(Bib *bib, book *book, int chosenBook)
{
    // let the user choose a book to borrow/return/delete the chosen book
    showChosenBook(chosenBook, book);

    // when a number was chosen: ask user what he wants to do with that book
    char *allowedChars = "azlc";
    char userChar[BUFFERSIZE];
    int isNotAborted;

    printf("[A]: Buch ausleihen\n");
    printf("[Z]: Buch zur%cckgeben\n", ue);
    printf("[L]: Buch l%cschen\n", oe);

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
            default:
                printf("Falsche Eingabe!\n");
                break;
        }
        stringToLower(menuHeader);
        printMenuEnd(menuHeader);
    }
}
