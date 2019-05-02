#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

void getSearchListById(List *list, int id) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->id == id) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByName(List *list, char *name) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByType(List *list, char *type) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->type, type) == 0) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByDescription(List *list, char *description) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->description, description) == 0) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByCount(List *list, int count) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->count == count) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByPrice(List *list, double price) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->price == price) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByStars(List *list, double stars) {
    ShopItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->stars == stars) {
            printf("%d. Title: %s\nType: %s\nDescription: %s\nCount: %d\nPrice: %lf\nStars: %lf\n\n", current->id,
                   current->name, current->type, current->description, current->count, current->price, current->stars);
            c++;
        }
        current = (ShopItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}
