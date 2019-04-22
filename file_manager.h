#ifndef COURSEWORK_FILE_MANAGER_H
#define COURSEWORK_FILE_MANAGER_H

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*Get String Length*/
int getStringSize(char *string);

/*Initialization String Field*/
char *initStringField(char *string);

/* Read List of items from CSV file*/
void readListFromFile(FILE *file, List *list);

/* Save List of items to CSV file*/
void saveListToFile(FILE *file, List *list);

#endif //COURSEWORK_FILE_MANAGER_H
