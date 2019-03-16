#include "loadBooks.h"

/*
 *  function:
 *      Loads the book data from the data.csv-file into a Bibliothek-structure.
 *  params:
 *      Bib *bib (pointer to the structure)
 */
void loadBooks(Bib *bib)
{
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
        // skip empty lines
        if(line[0] != '\n'){
            // initialize bib structure
            newBook(bib);
            records = strtok(line, delimiter);

            int index = 0;
            while(records){
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
                        break;
                    case 4:
                        // insert borrowlist
                        writeStringToArrayNode(bib, 'b', records);
                        break;
                }
                records = strtok(NULL, delimiter);
                index++;
            }
            bib->used++;
        }
    }
    fclose(dataFile);
}
