#include "loadBooks.h"

/*
 *  function:
 *      Loads the book data from the data.csv-file into a Bibliothek-structure.
 *  params:
 *      Bib *bib (pointer to the structure)
 */
void loadBooks(Bib *bib)
{
    //https://codereview.stackexchange.com/questions/44649/dynamic-array-of-structs-in-c
    // initialize array
//    int initialSize = 1;
    // Allocate initial space
    bib->books = malloc(0);
    bib->used = 0;
    bib->size = 0;

    // read every line of the csv-file and write data to the array
    char buffer[1024];
    char *line, *records;
    char delimiter[] = ";";
    FILE *dataFile = fopen("data.csv", "r");
    if(dataFile == NULL){
        printf("ERROR: Datenbank-Datei kann nicht gelesen werden!\n");
    }
    while((line=fgets(buffer,sizeof(buffer),dataFile))!=NULL){
//        printf("loop\n");
        // skip empty lines
        if(line[0] != '\n'){
//            line[strlen(line)-1] = '\0';
//            printf("line: %s\n", line);
            // initialize bib structure
            newBook(bib);
            records = strtok(line, delimiter);

            int index = 0;
            while(records){
//                printf("%s\n", records);
                switch(index){
                    case 0:
                        // insert isbn
                        writeStringToArrayNode(bib, 'i', records);
                        break;
                    case 1:
                        // insert title
                        writeStringToArrayNode(bib, 't', records);
                        break;
                    case 2:
                        // insert author
                        writeStringToArrayNode(bib, 'a', records);
                        break;
                    case 3:
                        // insert numberof
                        writeStringToArrayNode(bib, 'n', records);
//                        printf("strlen: %d\n", strlen(records));
//                        printf("string: %s\n", records);
//                        printf("before alloc\n");
//                        bib->books[bib->used].numberof = malloc(strlen(records));
////                        bib->books[bib->used].numberof = malloc(sizeof(records)*sizeof(char));
//                        printf("afer alloc\n");
//                        printf("array->numberof: %s\n", bib->books[bib->used].numberof);
//                        printf("record: %s\n", records);
//                        strncpy(bib->books[bib->used].numberof, records, strlen(records));
//                        printf("before before 0ing\n");
//                        bib->books[bib->used].numberof[strlen(records)] = '\0';
//                        printf("number of done\n");
                        break;
                    case 4:
                        // insert borrowlist
                        writeStringToArrayNode(bib, 'b', records);
                        break;
                }
    //            printf("%d:%s\n", index, records);
                records = strtok(NULL, delimiter);
                index++;
            }
    //        printf("\n");
            bib->used++;
        }
    }
    fclose(dataFile);
}
