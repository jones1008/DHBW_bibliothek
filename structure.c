#include "structure.h"

/*
 *  function:
 *      Adds a new book to the bib structure
 *  params:
 *      Bib *bib
 */
void newBook(Bib *bib)
{
    if (bib->used == bib->size){
        bib->size++;
        bib->books = realloc(bib->books, bib->size*sizeof(book));
    }
}

/*
 *  function:
 *      Writes a given string either to isbn, title, author, numberof or borrowlist in the bib structure to the last book entry.
 *  params:
 *      Bib *bib
 *      char node (a char that represents either isbn, title, author, numberof or borrowlist, so the function knows where to store the string)
 *      char *string (the string that should be written)
 */
void writeStringToArrayNode(Bib *bib, char node, char *string)
{
    switch(node){
        case 'i':
            printf("isbn: %s\n", string);
            printf("bib->used: %d\n", bib->used);
            bib->books[bib->used].isbn = calloc(strlen(string)+1, sizeof(char));
            printf("before copying\n");
            strncpy(bib->books[bib->used].isbn, string, strlen(string));
            printf("before writing null\n");
            bib->books[bib->used].isbn[strlen(string)] = '\0';
            printf("bib->isbn: %s\n", bib->books[bib->used].isbn);
            break;
        case 't':
            bib->books[bib->used].title = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].title, string, strlen(string));
            bib->books[bib->used].title[strlen(string)] = '\0';
            break;
        case 'a':
            bib->books[bib->used].author = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].author, string, strlen(string));
            bib->books[bib->used].author[strlen(string)] = '\0';
            break;
        case 'n':
            bib->books[bib->used].numberof = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].numberof, string, strlen(string));
            bib->books[bib->used].numberof[strlen(string)] = '\0';
            break;
        case 'b':
            bib->books[bib->used].borrowlist = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].borrowlist, string, strlen(string));
            if(string[0] != '\0'){
                bib->books[bib->used].borrowlist[strlen(string)-1] = '\0';
            } else{
                bib->books[bib->used].borrowlist[strlen(string)] = '\0';
            }
            break;
        default:
            printf("ERROR: Array-Item existiert nicht");
            break;
    }
}
