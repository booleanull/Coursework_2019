#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "file_manager.h"
#include "menu.h"

#define FILENAME "store.csv"

int main() {
    // Read data from file
    FILE *readFile = fopen(FILENAME, "r");
    List *list = makeList();
    readListFromFile(readFile, list);
    fclose(readFile);

    showMenu(list);

    // Save data to file
    FILE *writeFile = fopen(FILENAME, "w");
    saveListToFile(writeFile, list);
    destroy(list);
    fclose(writeFile);
    return 0;
}