#ifndef COURSEWORK_SEARCH_H
#define COURSEWORK_SEARCH_H

#include "list.h"

void getSearchListById(List *list, int id);

void getSearchListByName(List *list, char *name);

void getSearchListByType(List *list, char *type);

void getSearchListByDescription(List *list, char *description);

void getSearchListByCount(List *list, int count);

void getSearchListByPrice(List *list, double price);

void getSearchListByStars(List *list, double stars);

#endif //COURSEWORK_SEARCH_H
