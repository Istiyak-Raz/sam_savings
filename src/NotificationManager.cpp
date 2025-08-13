#include "NotificationManager.h"
#include <iostream>
#include <iomanip>
#include <ctime>

void NotificationManager::displayDailyNotifications(const Account& account) {
    std::cout << "\n--- Daily Update ---" << std::endl;
    std::cout << "Welcome back, " << "StudentUser" << "!" << std::endl; // Placeholder for username
    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
    std::cout << "Current Savings: $" << std::fixed << std::setprecision(2) << account.getCurrentSavings() << std::endl;

    // Display outstanding loans
    account.displayLoans();

    // Remind about daily update (simple placeholder for now)
    std::cout << "Don't forget to log your daily income and expenses!" << std::endl;
    std::cout << "--------------------" << std::endl;
}

void NotificationManager::displayWishlistNotifications(const Account& account) {
    account.displayWishlist(); // Re-use existing display method for now
}
