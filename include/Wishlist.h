#ifndef WISHLIST_H
#define WISHLIST_H

#include "WishlistItem.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>

class Wishlist {
private:
    std::vector<WishlistItem> items;

public:
    void addItem(const WishlistItem& item);
    void displayWishlist(double currentSavings) const;
};

#endif // WISHLIST_H
