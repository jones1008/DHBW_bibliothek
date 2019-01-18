#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main()
{
    int sqlite3_open("./data.db", sqlite3 **ppDb);
    printf("Hello world!\n");
    return 0;
}
