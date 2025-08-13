#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include "Account.h"
#include "UserManager.h"

class DataManager {
public:
    static void saveUserData(const UserManager& userManager, const std::string& filename);
    static void loadUserData(UserManager& userManager, const std::string& filename);

    static void saveAccountData(const Account& account, const std::string& filename);
    static void loadAccountData(Account& account, const std::string& filename);
};

#endif // DATA_MANAGER_H
