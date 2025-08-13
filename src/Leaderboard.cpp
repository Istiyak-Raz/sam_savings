#include "Leaderboard.h"

void Leaderboard::displayLeaderboard(const std::vector<std::unique_ptr<User>>& users) {
    std::cout << "\n--- Leaderboard ---" << std::endl;
    if (users.empty()) {
        std::cout << "No users to display on the leaderboard." << std::endl;
        return;
    }

    // Create a copy of pointers to sort (to avoid modifying the original unique_ptr vector)
    std::vector<User*> sortedUsers;
    for (const auto& user : users) {
        sortedUsers.push_back(user.get());
    }

    // Sort users by activity score in descending order
    std::sort(sortedUsers.begin(), sortedUsers.end(), [](const User* a, const User* b) {
        return a->getActivityScore() > b->getActivityScore();
    });

    // Display top 10 users
    for (size_t i = 0; i < sortedUsers.size() && i < 10; ++i) {
        std::cout << (i + 1) << ". " << sortedUsers[i]->getUsername()
                  << " (Score: " << sortedUsers[i]->getActivityScore() << ")" << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}

