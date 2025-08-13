#include "Wishlist.h"

void Wishlist::addItem(const WishlistItem& item) {
    items.push_back(item);
    std::cout << "Added '" << item.getName() << "' to wishlist." << std::endl;
}

void Wishlist::displayWishlist(double currentSavings) const {
    std::cout << "\n--- Your Wishlist ---" << std::endl;
    if (items.empty()) {
        std::cout << "Your wishlist is empty." << std::endl;
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            const WishlistItem& item = items[i];
            std::time_t tt = std::chrono::system_clock::to_time_t(item.getDeadline());
            double progress = (currentSavings / item.getCost()) * 100.0;
            if (progress > 100.0) progress = 100.0; // Cap at 100%

            std::cout << "Item " << i << ": " << item.getName()
                      << " (Cost: $" << std::fixed << std::setprecision(2) << item.getCost()
                      << ", Deadline: " << std::put_time(std::localtime(&tt), "%F %T")
                      << ", Progress: " << std::fixed << std::setprecision(2) << progress << "%) "
                      << "(Needs: $" << std::fixed << std::setprecision(2) << item.getCost() - currentSavings << ")" << std::endl;
            std::cout << "  Description: " << item.getDescription() << std::endl;
        }
    }
    std::cout << "---------------------" << std::endl;
}
