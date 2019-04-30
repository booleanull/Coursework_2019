#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int getStringSize(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i + 1;
}

char *initStringField(char *string) {
    int len = getStringSize(string);
    char *str = (char *) malloc(len * sizeof(char));

    strcpy(str, string);
    return str;
}

void readListFromFile(FILE *file, List *list) {
    if (file != NULL) {
        char scanner[1024];
        while (fgets(scanner, 1024, file)) {
            ShopItem *item = malloc(sizeof(ShopItem));
            int count = 0;
            char *words = strtok(scanner, ";");
            while (words != NULL) {
                if(count == 0) {
                    item->name = initStringField(words);
                }
                else if(count == 1) {
                    item->type = initStringField(words);
                }
                else if(count == 2) {
                    item->description = initStringField(words);
                }
                else if(count == 3) {
                    item->count = atoi(words);
                }
                else if(count == 4) {
                    item->price = atof(words);
                }
                else if(count == 5) {
                    item->stars = atof(words);
                }

                count++;
                words = strtok(NULL, ";,");
            }

            add(item, list);
        }
    }
}

void saveListToFile(FILE *file, List *list) {
    ShopItem *current = list->head;
    if (current == NULL)
        return;

    while (current != NULL) {
        fprintf(file, "%s;%s;%s;%d;%lf;%lf\n", current->name, current->type, current->description, current->count, current->price, current->stars);
        current = (ShopItem *) current->next;
    }
}
