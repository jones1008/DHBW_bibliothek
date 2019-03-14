#include "structure.h"

void newBook(Bib *bib)
{
    // TODO: brauchen wir ->size überhaupt?
    if (bib->used == bib->size){
        bib->size++;
        bib->books = realloc(bib->books, bib->size*sizeof(book));
    }
}

void writeStringToArrayNode(Bib *bib, char node, char *string)
{
//    printf("strlen: %d\n", strlen(string));
//    printf("string: %s\n", string);
    switch(node){
        case 'i':
//            printf("saving isbn\n");
            bib->books[bib->used].isbn = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].isbn, string, strlen(string));
//            if(string[strlen(string)-1] != '\0'){
                bib->books[bib->used].isbn[strlen(string)] = '\0';
//            }
            break;
        case 't':
//            printf("before saving title\n");
//            printf("array-title: %s\n", bib->books[bib->used].title);
//            printf("bib->used: %d\n", bib->used);
//            printf("strlen: %d\n", strlen(string));
            bib->books[bib->used].title = malloc((strlen(string)+1)*sizeof(char));
//            printf("before strncpy\n");
            strncpy(bib->books[bib->used].title, string, strlen(string));
//            printf("before 0 terminator\n");
//            if(string[strlen(string)-1] != '\0'){
                bib->books[bib->used].title[strlen(string)] = '\0';
//            }
            break;
        case 'a':
//            printf("saving author\n");
            bib->books[bib->used].author = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].author, string, strlen(string));
//            if(string[strlen(string)-1] != '\0'){
                bib->books[bib->used].author[strlen(string)] = '\0';
//            }
            break;
        case 'n':
//            printf("strlen: %d\n", strlen(string));
//            printf("string: %s\n", string);
//            printf("before alloc\n");
            bib->books[bib->used].numberof = malloc((strlen(string)+1)*sizeof(char));
//            printf("afer alloc\n");
//            printf("array->numberof: %s\n", bib->books[bib->used].numberof);
//            printf("record: %s\n", string);
            strncpy(bib->books[bib->used].numberof, string, strlen(string));
//            printf("before before 0ing\n");
//            if(string[strlen(string)-1] != '\0'){
                bib->books[bib->used].numberof[strlen(string)] = '\0';
//            }
//            printf("number of done\n");
            break;
        case 'b':
//            printf("before borrowlist\n");
            bib->books[bib->used].borrowlist = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->books[bib->used].borrowlist, string, strlen(string));
//            printf("last char of string: %d\n", string[strlen(string)-1]);
//            printf("strlen(string): %d\n", strlen(string));
//            if(string[strlen(string)-1] != '\0'){
            if(string[0] != '\0'){
//                printf("is null\n");
                bib->books[bib->used].borrowlist[strlen(string)-1] = '\0';
            } else{
                bib->books[bib->used].borrowlist[strlen(string)] = '\0';
            }
//            }
//            printf("after borrowlist\n");
//            bib->books[bib->used].borrowlist[strlen(string)] = '\0';
            break;
        default:
            printf("ERROR: Array-Item existiert nicht");
            break;
    }
}
