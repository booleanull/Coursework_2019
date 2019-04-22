#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "file_manager.h"

void showDelete(List *list);

void showAbout() {
    char cont[80];
    system("cls");
    puts("================= [About] ===================");
    puts("Some info!");
    puts("=============================================");
    printf("Write anything to continue: ");
    scanf(" %s", &cont);
}

void showAdd(List *list) {
    char string[1024];
    ShopItem *shopItem = malloc(sizeof(ShopItem));
    char cont[80];

    system("cls");
    puts("================== [Add] ====================");
    puts("Some info!");
    puts("=============================================");

    printf("Write name of item: ");
    scanf("%s", &string);
    shopItem->name = initStringField(string);

    printf("Write description of item: ");
    scanf("%s", &string);
    shopItem->description = initStringField(string);

    printf("Write count of items: ");
    while (scanf(" %d", &shopItem->count) != 1) {
        printf("Write count of items: ");
    }

    printf("Write price of item: ");
    while (scanf("%lf", &shopItem->price) != 1) {
        printf("Write price of item: ");
    }

    printf("Write stars of item: ");
    while (scanf("%lf", &shopItem->stars) != 1) {
        printf("Write stars of item: ");
    }

    add(shopItem, list);
    puts("Item wad added to store");
    printf("Write anything to continue: ");
    scanf(" %s", &cont);
}

void showEdit(List *list) {
    int id = 0;
    char string[1024];
    char cont[80];

    system("cls");
    puts("================= [Edit] ====================");
    puts("Some info!");
    puts("=============================================");
    printf("Write ID of note to edit: ");
    scanf("%d", &id);
    ShopItem *shopItem = get(id, list);

    if (shopItem == NULL) {
        puts("There is no such id");
        printf("Write anything to continue: ");
        scanf(" %s", &cont);
    } else {
        printf("Write name of item: ");
        scanf("%s", &string);
        shopItem->name = initStringField(string);

        printf("Write description of item: ");
        scanf("%s", &string);
        shopItem->description = initStringField(string);

        printf("Write count of items: ");
        while (scanf(" %d", &shopItem->count) != 1) {
            printf("Write count of items: ");
        }

        printf("Write price of item: ");
        while (scanf("%lf", &shopItem->price) != 1) {
            printf("Write price of item: ");
        }

        printf("Write stars of item: ");
        while (scanf("%lf", &shopItem->stars) != 1) {
            printf("Write stars of item: ");
        }
        puts("Item wad edited");
        printf("Write anything to continue: ");
        scanf(" %s", &cont);
    }
}

void showDelete(List *list) {
    int id = 0;
    char cont[80];

    system("cls");
    puts("================ [Delete] ===================");
    puts("Some info!");
    puts("=============================================");
    printf("Write ID of note to edit: ");
    scanf("%d", &id);
    ShopItem *shopItem = get(id, list);

    if (shopItem == NULL) {
        puts("There is no such id");
        printf("Write anything to continue: ");
        scanf(" %s", &cont);
    } else {
        delete(id, list);
        puts("Item wad deleted");
        printf("Write anything to continue: ");
        scanf(" %s", &cont);
    }
}

void showMenu(List *list) {
    int menu = 0;
    while (menu != 7) {
        system("cls");
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
        printf("Write your command: ");

        while (scanf(" %d", &menu) != 1) {
            menu = 0;
            showMenu(list);
        }

        if (menu == 0) {
            showAbout();
        }
        else if (menu == 1) {
            showAdd(list);
        }
        else if (menu == 2) {
            showEdit(list);
        }
        else if (menu == 3) {
            showDelete(list);
        }
        else if (menu == 4) {
            char cont[80];
            system("cls");
            puts("================= [List] ====================");
            display(list);
            puts("=============================================");
            printf("Write anything to continue: ");
            scanf(" %s", &cont);
        }
    }
}