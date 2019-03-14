#include "structure.h"

void newBook(Bib *bib)
{
    // TODO: brauchen wir ->size überhaupt?
    if (bib->used == bib->size){
        bib->size++;
        bib->array = realloc(bib->array, bib->size*sizeof(book));
    }
}

void writeStringToArrayNode(Bib *bib, char node, char *string)
{
//    printf("strlen: %d\n", strlen(string));
//    printf("string: %s\n", string);
    switch(node){
        case 'i':
//            printf("saving isbn\n");
            bib->array[bib->used].isbn = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->array[bib->used].isbn, string, strlen(string));
//            if(string[strlen(string)-1] != '\0'){
                bib->array[bib->used].isbn[strlen(string)] = '\0';
//            }
            break;
        case 't':
//            printf("before saving title\n");
//            printf("array-title: %s\n", bib->array[bib->used].title);
//            printf("bib->used: %d\n", bib->used);
//            printf("strlen: %d\n", strlen(string));
            bib->array[bib->used].title = malloc((strlen(string)+1)*sizeof(char));
//            printf("before strncpy\n");
            strncpy(bib->array[bib->used].title, string, strlen(string));
//            printf("before 0 terminator\n");
//            if(string[strlen(string)-1] != '\0'){
                bib->array[bib->used].title[strlen(string)] = '\0';
//            }
            break;
        case 'a':
//            printf("saving author\n");
            bib->array[bib->used].author = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->array[bib->used].author, string, strlen(string));
//            if(string[strlen(string)-1] != '\0'){
                bib->array[bib->used].author[strlen(string)] = '\0';
//            }
            break;
        case 'n':
//            printf("strlen: %d\n", strlen(string));
//            printf("string: %s\n", string);
//            printf("before alloc\n");
            bib->array[bib->used].numberof = malloc((strlen(string)+1)*sizeof(char));
//            printf("afer alloc\n");
//            printf("array->numberof: %s\n", bib->array[bib->used].numberof);
//            printf("record: %s\n", string);
            strncpy(bib->array[bib->used].numberof, string, strlen(string));
//            printf("before before 0ing\n");
//            if(string[strlen(string)-1] != '\0'){
                bib->array[bib->used].numberof[strlen(string)] = '\0';
//            }
//            printf("number of done\n");
            break;
        case 'b':
//            printf("before borrowlist\n");
            bib->array[bib->used].borrowlist = malloc((strlen(string)+1)*sizeof(char));
            strncpy(bib->array[bib->used].borrowlist, string, strlen(string));
//            printf("last char of string: %d\n", string[strlen(string)-1]);
//            printf("strlen(string): %d\n", strlen(string));
//            if(string[strlen(string)-1] != '\0'){
            if(string[0] != '\0'){
//                printf("is null\n");
                bib->array[bib->used].borrowlist[strlen(string)-1] = '\0';
            } else{
                bib->array[bib->used].borrowlist[strlen(string)] = '\0';
            }
//            }
//            printf("after borrowlist\n");
//            bib->array[bib->used].borrowlist[strlen(string)] = '\0';
            break;
        default:
            printf("ERROR: Array-Item existiert nicht");
            break;
    }
}
