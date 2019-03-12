#include "structure.h"

void newBook(Array *books)
{
    if (books->used == books->size){
        books->size *= 2;
        books->array = (book *)realloc(books->array, books->size * sizeof(book));
    }
}

void writeStringToArrayNode(Array *books, char node, char *string)
{
//    printf("strlen: %d\n", strlen(string));
//    printf("string: %s\n", string);
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
//            printf("strlen: %d\n", strlen(string));
//            printf("string: %s\n", string);
//            printf("before alloc\n");
            books->array[books->used].numberof = malloc(strlen(string));
//            printf("afer alloc\n");
//            printf("array->numberof: %s\n", books->array[books->used].numberof);
//            printf("record: %s\n", string);
            strncpy(books->array[books->used].numberof, string, strlen(string));
//            printf("before before 0ing\n");
            books->array[books->used].numberof[strlen(string)] = '\0';
//            printf("number of done\n");
//            printf("before alloc\n");
//            books->array[books->used].numberof = malloc(strlen(string));
//            printf("afer alloc\n");
//            strncpy(books->array[books->used].numberof, string, strlen(string));
//            printf("before before 0ing\n");
//            books->array[books->used].numberof[strlen(string)] = '\0';
//            printf("number of done\n");
            break;
        case 'b':
//            printf("before borrowlist\n");
            books->array[books->used].borrowlist = malloc(strlen(string));
            strncpy(books->array[books->used].borrowlist, string, strlen(string));
            books->array[books->used].borrowlist[strlen(string)-1] = '\0';
//            printf("after borrowlist\n");
//            books->array[books->used].borrowlist[strlen(string)] = '\0';
            break;
        default:
            printf("ERROR: Array-Item existiert nicht");
            break;
    }
}
