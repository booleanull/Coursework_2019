#include <string.h>
#include "list.h"
#include "file_manager.h"

void swap(ShopItem *a, ShopItem *b) {
    int id = a->id;
    char *name = initStringField(a->name);
    char *type = initStringField(a->type);
    char *description = initStringField(a->description);
    int count = a->count;
    double price = a->price;
    double stars = a->stars;

    a->id = b->id;
    a->name = b->name;
    a->type = b->type;
    a->description = b->description;
    a->count = b->count;
    a->price = b->price;
    a->stars = b->stars;

    b->id = id;
    b->name = name;
    b->type = type;
    b->description = description;
    b->count = count;
    b->price = price;
    b->stars = stars;
}

void sortById(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (shopItem->id > shopItemNext->id) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByName(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (strcmp(shopItem->name, shopItemNext->name) > 0) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByType(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (strcmp(shopItem->type, shopItemNext->type) > 0) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByDescription(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (strcmp(shopItem->description, shopItemNext->description) > 0) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByCount(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (shopItem->id > shopItemNext->id) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByPrice(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (shopItem->id > shopItemNext->id) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByStars(List *list) {
    int swapped;
    ShopItem *shopItem;
    ShopItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (ShopItem *) shopItem->next;
            if (shopItem->id > shopItemNext->id) {
                swap(shopItem, (ShopItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (ShopItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}