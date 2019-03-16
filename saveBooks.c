#include "saveBooks.h"

/*
 *  function:
 *      Converts the bib structure into a string (line) and writes them to the data.csv to save the current bib-structure
 *  params:
 *      Bib *bib
 */
void saveBooks(Bib *bib)
{
    // loop over the structure
    int fileSuccess = 1;
    for(int i=0; i<bib->used; i++){
        // skip line, if book was deleted
        if(!(bib->books[i].isbn == NULL && bib->books[i].title == NULL && bib->books[i].author == NULL && bib->books[i].numberof == NULL && bib->books[i].borrowlist == NULL)){
            // get length of the line and concatenate the attributes to the line
            int lineSize = 6+strlen(bib->books[i].isbn)+strlen(bib->books[i].title)+strlen(bib->books[i].author)+strlen(bib->books[i].numberof)+strlen(bib->books[i].borrowlist);
            char line[lineSize];
            snprintf(line, lineSize, "%s;%s;%s;%s;%s\n", bib->books[i].isbn, bib->books[i].title, bib->books[i].author, bib->books[i].numberof, bib->books[i].borrowlist);

            // write first line and append the following lines
            FILE *dataFile;
            if(i==0){
                dataFile = fopen("data.csv", "w");
            } else{
                dataFile = fopen("data.csv", "a");
            }
            if(dataFile == NULL){
                printf("ERROR: Problem beim Öffnen der Datenbank-Datei: %s\n", strerror(errno));
                fileSuccess = 0;

                fclose(dataFile);
                break;
            } else{
                fprintf(dataFile, "%s", line);
            }
            fclose(dataFile);
        }
    }
    if(fileSuccess){
        printf("---> Datenbank erfolgreich aktualisiert!\n");

        // reload bib structure from file after saving
        loadBooks(bib);
    }
}
