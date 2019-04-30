#ifndef COURSEWORK_ITEM_H
#define COURSEWORK_ITEM_H

typedef struct {
    int id;                     // Id
    char *name;                 // Name of Item
    char *type;                 // Type of Item
    char *description;          // Description of Item
    int count;                  // Number of Items
    double price;               // Price of Item
    double stars;               // Popularity
    struct ShopItem *next;      // Link to next
} ShopItem;

#endif //COURSEWORK_ITEM_H
