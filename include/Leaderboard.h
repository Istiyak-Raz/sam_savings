#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "User.h"
#include <vector>
#include <algorithm> // For std::sort
#include <iostream>

class Leaderboard {
public:
    static void displayLeaderboard(const std::vector<std::unique_ptr<User>>& users);
};

#endif // LEADERBOARD_H
