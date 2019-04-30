#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "list.h"
#include "file_manager.h"
#include "checks.h"
#include "search.h"
#include "sort.h"

// For adaptive clear screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

ShopItem *readItem(ShopItem *shopItem) {
    shopItem->name = enterString("Write name of item: ");
    shopItem->type = enterString("Write type of item: ");
    shopItem->description = enterString("Write description of item: ");

    shopItem->count = enterInt("Write count of items: ");
    shopItem->price = enterDouble("Write price of item: ");
    shopItem->stars = enterDouble("Write stars of item: ");

    return shopItem;
}

void showAbout() {
    system(CLEAR);
    puts("================= [About] ===================");
    puts("Title: \"Shop Manager\"");
    puts("Author: Zub Vitaliy 8307");
    puts("Description: In the application, you can\nstore your store data in a structured\nway. Follow the menu to work with the\napplication.");
    puts("=============================================");
    printf("Press anything to continue: ");
    getch();
}

void showAdd(List *list) {
    ShopItem *shopItem = malloc(sizeof(ShopItem));

    system(CLEAR);
    puts("================== [Add] ====================");
    puts("At this point you can add a new item\nto the library. Follow the instructions.");
    puts("=============================================");

    readItem(shopItem);

    add(shopItem, list);
    puts("Item wad added to library");
    printf("Write anything to continue: ");
    getch();
}

void showEdit(List *list) {
    int id = 0;

    system(CLEAR);
    puts("================= [Edit] ====================");
    puts("At this point you can edit item\nfrom the library. Follow the instructions.");
    puts("=============================================");

    id = enterInt("Write ID of note to edit: ");

    ShopItem *shopItem = get(id, list);

    if (shopItem == NULL) {
        puts("There is no such id");
        printf("Write anything to continue: ");
        getch();
    } else {
        readItem(shopItem);

        puts("Item wad edited");
        printf("Write anything to continue: ");
        getch();
    }
}

void showDelete(List *list) {
    int id = 0;

    system(CLEAR);
    puts("================ [Delete] ===================");
    puts("At this point you can delete item\nfrom the library. Follow the instructions.");
    puts("=============================================");
    id = enterInt("Write ID of note to delete: ");
    ShopItem *shopItem = get(id, list);

    if (shopItem == NULL) {
        puts("There is no such id");
        printf("Write anything to continue: ");
        getch();
    } else {
        delete(id, list);
        puts("Item wad deleted");
        printf("Write anything to continue: ");
        getch();
    }
}

void showList(List *list) {
    system(CLEAR);
    puts("================= [List] ====================");
    display(list);
    puts("=============================================");
    printf("Write anything to continue: ");
    getch();
}

void showSearchMenu(List *list) {
    int id = 0;
    system(CLEAR);
    puts("================ [Search] ===================");
    puts("0. ID");
    puts("1. Name");
    puts("2. Type");
    puts("3. Description");
    puts("4. Count");
    puts("5. Price");
    puts("6. Stars");
    puts("=============================================");
    id = enterInt("Write your field: ");

    if (id == 0) {
        id = enterInt("Write id of item: ");
        puts("");
        getSearchListById(list, id);
    } else if (id == 1) {
        char *name = enterString("Write name of item: ");
        puts("");
        getSearchListByName(list, name);
    } else if (id == 2) {
        char *type = enterString("Write type of item: ");
        puts("");
        getSearchListByType(list, type);
    } else if (id == 3) {
        char *description = enterString("Write description of item: ");
        puts("");
        getSearchListByDescription(list, description);
    } else if (id == 4) {
        int count = enterInt("Write count of items: ");
        puts("");
        getSearchListByCount(list, count);
    } else if (id == 5) {
        double price = enterDouble("Write price of item: ");
        puts("");
        getSearchListByPrice(list, price);
    } else if (id == 6) {
        double stars = enterDouble("Write stars of item: ");
        puts("");
        getSearchListByStars(list, stars);
    }
    printf("Write anything to continue: ");
    getch();
}

void showSortMenu(List *list) {
    int id = 0;
    system(CLEAR);
    puts("================= [Sort] ====================");
    puts("0. ID");
    puts("1. Name");
    puts("2. Type");
    puts("3. Description");
    puts("4. Count");
    puts("5. Price");
    puts("6. Stars");
    puts("=============================================");
    id = enterInt("Write your field: ");

    if (id == 0) {
        sortById(list);
    } else if (id == 1) {
        sortByName(list);
    } else if (id == 2) {
        sortByType(list);
    } else if (id == 3) {
        sortByDescription(list);
    } else if (id == 4) {
        sortByCount(list);
    } else if (id == 5) {
        sortByPrice(list);
    } else if (id == 6) {
        sortByStars(list);
    }
    puts("List was sorted");
    printf("Write anything to continue: ");
    getch();
}

void showMenu(List *list) {
    int menu = 0;
    while (menu != 7) {
        system(CLEAR);
        puts("================= [MENU] ===================");
        puts("0. About");
        puts("1. Add new note");
        puts("2. Edit note");
        puts("3. Delete note");
        puts("4. Print list");
        puts("5. Search");
        puts("6. Sort");
        puts("7. Exit");
        puts("============================================");
        menu = enterInt("Write your command: ");

        if (menu == 0) {
            showAbout();
        } else if (menu == 1) {
            showAdd(list);
        } else if (menu == 2) {
            showEdit(list);
        } else if (menu == 3) {
            showDelete(list);
        } else if (menu == 4) {
            showList(list);
        } else if (menu == 5) {
            showSearchMenu(list);
        } else if (menu == 6) {
            showSortMenu(list);
        }
    }
}