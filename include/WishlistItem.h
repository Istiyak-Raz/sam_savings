#ifndef WISHLIST_ITEM_H
#define WISHLIST_ITEM_H

#include <string>
#include <chrono>

class WishlistItem {
private:
    std::string name;
    double cost;
    std::chrono::system_clock::time_point deadline;
    std::string description;

public:
    WishlistItem(const std::string& name, double cost, const std::chrono::system_clock::time_point& deadline, const std::string& description);

    std::string getName() const;
    double getCost() const;
    std::chrono::system_clock::time_point getDeadline() const;
    std::string getDescription() const;
    std::string toString() const;
};

#endif // WISHLIST_ITEM_H
