#include "loadBooks.h"
void loadBooks(Array *books)
{
    //https://codereview.stackexchange.com/questions/44649/dynamic-array-of-structs-in-c
    // initialize array
    int initialSize = 1;
    // Allocate initial space
    books->array = (book *)calloc(initialSize * sizeof(book), sizeof(int));
    books->used = 0;           // no elements used
    books->size = initialSize; // available nr of elements

    // read every line of the csv-file and write data to the array
    char buffer[1024];
    char *line, *records;
    char delimiter[] = ";";
    FILE *dataFile = fopen("data.csv", "r");
    if(dataFile == NULL){
        printf("Can't read data file!");
    }
    while((line=fgets(buffer,sizeof(buffer),dataFile))!=NULL){
        if (books->used == books->size){
            books->size *= 2;
            books->array = (book *)realloc(books->array, books->size * sizeof(book));
        }
        records = strtok(line, delimiter);

        int index = 0;
        while(records){
//            printf("%s", records);
            switch(index){
                case 0:
                    // insert isbn
                    books->array[books->used].isbn = (char*)malloc(strlen(records) + 1);
                    strcpy(books->array[books->used].isbn, records);
                    break;
                case 1:
                    // insert title
                    books->array[books->used].title = (char*)malloc(strlen(records) + 1);
                    strcpy(books->array[books->used].title, records);
                    break;
                case 2:
                    // insert author
                    books->array[books->used].author = (char*)malloc(strlen(records) + 1);
                    strcpy(books->array[books->used].author, records);
                    break;
                case 3:
                    // insert numberof
                    books->array[books->used].numberof = (char*)malloc(strlen(records) + 1);
                    strcpy(books->array[books->used].numberof, records);
                    break;
                case 4:
                    // insert borrowlist
                    books->array[books->used].borrowlist = (char*)malloc(strlen(records) + 1);
                    strcpy(books->array[books->used].borrowlist, records);
                    break;
            }
//            printf("%d:%s\n", index, records);
            records = strtok(NULL, delimiter);
            index++;
        }
//        printf("\n");
        books->used++;
    }
    fclose(dataFile);
}
