#include "structure.h"

void newBook()
{

}

void writeStringToArrayNode(Array *books, char node, char *string)
{
    switch(node){
        case 'i':
            books->array[books->used].isbn = malloc(strlen(string));
            strncpy(books->array[books->used].isbn, string, strlen(string));
            books->array[books->used].isbn[strlen(string)] = '\0';
            break;
        case 't':
            books->array[books->used].title = malloc(strlen(string));
            strncpy(books->array[books->used].title, string, strlen(string));
            books->array[books->used].title[strlen(string)] = '\0';
            break;
        case 'a':
            books->array[books->used].author = malloc(strlen(string));
            strncpy(books->array[books->used].author, string, strlen(string));
            books->array[books->used].author[strlen(string)] = '\0';
            break;
        case 'n':
            books->array[books->used].numberof = malloc(strlen(string));
            strncpy(books->array[books->used].numberof, string, strlen(string));
            books->array[books->used].numberof[strlen(string)] = '\0';
            break;
        case 'b':
            books->array[books->used].borrowlist = malloc(strlen(string));
            strncpy(books->array[books->used].borrowlist, string, strlen(string));
            books->array[books->used].borrowlist[strlen(string)-1] = '\0';
//            books->array[books->used].borrowlist[strlen(string)] = '\0';
            break;
        default:
            printf("ERROR: Array-Item existiert nicht");
            break;
    }
}
