#include "saveBooks.h"

/*
 *  function:
 *      Converts the bib structure into a string (line) and writes them to the data.csv to save the current bib-structure
 *  params:
 *      Bib *bib
 */
void saveBooks(Bib *bib)
{
    printf("bib-> used: %d\n", bib->used);
    // loop over the structure
//    int fileSuccess = 1;
    int firstTimeOpened = 1;
    printf("before calloc\n");
//    char *line = calloc(10000, 1);
    char line[BUFFERSIZE*10];
    printf("before memset\n");
//    memset(line, 0, 10000*sizeof(char));
    for(int i=0; i<bib->used; i++){
        printf("loop\n");
        // skip line, if book was deleted
        if(!(bib->books[i].isbn == NULL && bib->books[i].title == NULL && bib->books[i].author == NULL && bib->books[i].numberof == NULL && bib->books[i].borrowlist == NULL)){
            // get length of the line and concatenate the attributes to the line
            int lineSize = 6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
//            char line[lineSize];
//            char line[lineSize];
//            printf("beofre realloc\n");
//            line = realloc(line, lineSize*sizeof(char));
//            memcpy(newPointer, oldPointer, sizeOfDataType * oldNum);
            if(firstTimeOpened){
                printf("before first snprintf\n");
                snprintf(line, lineSize, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
                printf("after first snprintf\n");
                firstTimeOpened = 0;
            } else{
                snprintf(line, lineSize, "%s%s;%s;%s;%s;%s\n", line, bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);
            }
        }
    }
    // write first line and append the following lines
    FILE *dataFile;
//    if(firstTimeOpened){
        dataFile = fopen("data.csv", "w");
//        firstTimeOpened = 0;
//    } else{
//        dataFile = fopen("data.csv", "a");
//    }
    if(dataFile == NULL){
        printf("ERROR: Problem beim Öffnen der Datenbank-Datei: %s\n", strerror(errno));
//        fileSuccess = 0;
//        if(fileSuccess){
//    }
//        fclose(dataFile);
//        break;
    } else{
        // TODO: stürzt hier bei fprintf ab (test ob saveBooks allgemein abstürzt oder nur bei borrowbook) -> wenns tut, dann ein Video machen von allen Funktionen
        // TODO: auch Fehler beim Ausleihen: newBorrowList ist nur letzter Buchstabe
        printf("line: %s\n", line);
//                fflush(dataFile);
//                fprintf(dataFile, "%s", line);
        fwrite(line, sizeof(line), sizeof(char), dataFile);
        printf("after fprintf\n");

        printf("---> Datenbank erfolgreich aktualisiert!\n");

        // reload bib structure from file after saving
        printf("before loadingBooks\n");
        loadBooks(bib);
    }
    fclose(dataFile);
}
