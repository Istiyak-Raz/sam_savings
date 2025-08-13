#include "UserManager.h"
#include <iostream>
#include <algorithm>

UserManager::UserManager() {}

User* UserManager::createUser(const std::string& username) {
    // Check if user already exists
    for (const auto& user : users) {
        if (user->getUsername() == username) {
            std::cout << "User '" << username << "' already exists." << std::endl;
            return nullptr;
        }
    }
    users.push_back(std::make_unique<User>(username));
    std::cout << "User '" << username << "' created." << std::endl;
    return users.back().get(); // Return pointer to the newly created user
}

User* UserManager::getUserByUsername(const std::string& username) {
    for (const auto& user : users) {
        if (user->getUsername() == username) {
            return user.get();
        }
    }
    return nullptr; // User not found
}

const std::vector<std::unique_ptr<User>>& UserManager::getAllUsers() const {
    return users;
}
