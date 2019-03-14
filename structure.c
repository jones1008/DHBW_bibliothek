#include "structure.h"

void newBook(Bib *books)
{
    // TODO: brauchen wir ->size überhaupt?
    if (books->used == books->size){
        books->size++;
        books->array = realloc(books->array, books->size*sizeof(book));
    }
}

void writeStringToArrayNode(Bib *books, char node, char *string)
{
//    printf("strlen: %d\n", strlen(string));
//    printf("string: %s\n", string);
    switch(node){
        case 'i':
//            printf("saving isbn\n");
            books->array[books->used].isbn = malloc((strlen(string)+1)*sizeof(char));
            strncpy(books->array[books->used].isbn, string, strlen(string));
//            if(string[strlen(string)-1] != '\0'){
                books->array[books->used].isbn[strlen(string)] = '\0';
//            }
            break;
        case 't':
//            printf("before saving title\n");
//            printf("array-title: %s\n", books->array[books->used].title);
//            printf("books->used: %d\n", books->used);
//            printf("strlen: %d\n", strlen(string));
            books->array[books->used].title = malloc((strlen(string)+1)*sizeof(char));
//            printf("before strncpy\n");
            strncpy(books->array[books->used].title, string, strlen(string));
//            printf("before 0 terminator\n");
//            if(string[strlen(string)-1] != '\0'){
                books->array[books->used].title[strlen(string)] = '\0';
//            }
            break;
        case 'a':
//            printf("saving author\n");
            books->array[books->used].author = malloc((strlen(string)+1)*sizeof(char));
            strncpy(books->array[books->used].author, string, strlen(string));
//            if(string[strlen(string)-1] != '\0'){
                books->array[books->used].author[strlen(string)] = '\0';
//            }
            break;
        case 'n':
//            printf("strlen: %d\n", strlen(string));
//            printf("string: %s\n", string);
//            printf("before alloc\n");
            books->array[books->used].numberof = malloc((strlen(string)+1)*sizeof(char));
//            printf("afer alloc\n");
//            printf("array->numberof: %s\n", books->array[books->used].numberof);
//            printf("record: %s\n", string);
            strncpy(books->array[books->used].numberof, string, strlen(string));
//            printf("before before 0ing\n");
//            if(string[strlen(string)-1] != '\0'){
                books->array[books->used].numberof[strlen(string)] = '\0';
//            }
//            printf("number of done\n");
            break;
        case 'b':
//            printf("before borrowlist\n");
            books->array[books->used].borrowlist = malloc((strlen(string)+1)*sizeof(char));
            strncpy(books->array[books->used].borrowlist, string, strlen(string));
//            printf("last char of string: %d\n", string[strlen(string)-1]);
//            printf("strlen(string): %d\n", strlen(string));
//            if(string[strlen(string)-1] != '\0'){
            if(string[0] != '\0'){
//                printf("is null\n");
                books->array[books->used].borrowlist[strlen(string)-1] = '\0';
            } else{
                books->array[books->used].borrowlist[strlen(string)] = '\0';
            }
//            }
//            printf("after borrowlist\n");
//            books->array[books->used].borrowlist[strlen(string)] = '\0';
            break;
        default:
            printf("ERROR: Array-Item existiert nicht");
            break;
    }
}
