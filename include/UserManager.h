#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "User.h"
#include <vector>
#include <string>
#include <memory> // For std::unique_ptr

class UserManager {
private:
    std::vector<std::unique_ptr<User>> users;

public:
    UserManager();
    User* createUser(const std::string& username);
    User* getUserByUsername(const std::string& username);
    const std::vector<std::unique_ptr<User>>& getAllUsers() const;
};

#endif // USER_MANAGER_H
