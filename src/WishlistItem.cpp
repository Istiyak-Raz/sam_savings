#include "WishlistItem.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Utils.h" // Include the new utility header

// Removed local definition of timePointToString

WishlistItem::WishlistItem(const std::string& name, double cost, const std::chrono::system_clock::time_point& deadline, const std::string& description)
    : name(name), cost(cost), deadline(deadline), description(description) {}

std::string WishlistItem::getName() const {
    return name;
}

double WishlistItem::getCost() const {
    return cost;
}

std::chrono::system_clock::time_point WishlistItem::getDeadline() const {
    return deadline;
}

std::string WishlistItem::getDescription() const {
    return description;
}

std::string WishlistItem::toString() const {
    return name + "," + std::to_string(cost) + "," + timePointToString(deadline) + "," + description;
}
