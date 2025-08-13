#ifndef NOTIFICATION_MANAGER_H
#define NOTIFICATION_MANAGER_H

#include <string>
#include <chrono>
#include "Account.h" // To access account data

class NotificationManager {
public:
    static void displayDailyNotifications(const Account& account);
    static void displayWishlistNotifications(const Account& account);
};

#endif // NOTIFICATION_MANAGER_H
