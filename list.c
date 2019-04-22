#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "item.h"

List *makeList() {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(ShopItem* item, List *list) {
    ShopItem *current = NULL;
    item->next = NULL;
    item->id = 0;

    if (list->head == NULL) {
        list->head = item;
    } else {
        item->id++;
        current = list->head;
        while (current->next != NULL) {
            item->id++;
            current = (ShopItem *) current->next;
        }
        current->next = (struct ShopItem *) item;
    }
}

ShopItem *get(int id, List *list) {
    ShopItem *current = list->head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = (ShopItem *) current->next;
    }
    return NULL;
}

int delete(int id, List *list) {
    ShopItem *current = list->head;
    ShopItem *previous = current;
    while (current != NULL) {
        if (current->id == id) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (ShopItem *) current->next;
            free(current);
            return 1;
        }
        previous = current;
        current = (ShopItem *) current->next;
    }
    return 0;
}

void display(List *list) {
    ShopItem *current = list->head;
    if (current == NULL)
        return;

    while (current != NULL) {
        printf("%d. %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n", current->id, current->name, current->description, current->count, current->price, current->stars);
        current = (ShopItem *) current->next;
    }
}

void destroy(List *list) {
    ShopItem *current = list->head;
    ShopItem *next = current;
    while (current != NULL) {
        next = (ShopItem *) current->next;
        free(current);
        current = next;
    }
    free(list);
}