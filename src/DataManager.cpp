#include "DataManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string> // For std::getline
#include "Utils.h" // Include the new utility header

// Removed local definitions of timePointToString and stringToTimePoint

void DataManager::saveUserData(const UserManager& userManager, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& user : userManager.getAllUsers()) {
            outFile << user->getUsername() << ","
                    << user->getRank() << ","
                    << user->getActivityScore() << "\n";
        }
        outFile.close();
        std::cout << "User data saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for saving user data: " << filename << std::endl;
    }
}

void DataManager::loadUserData(UserManager& userManager, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string username_str, rank_str, activityScore_str;
            std::getline(ss, username_str, ',');
            std::getline(ss, rank_str, ',');
            std::getline(ss, activityScore_str, ',');

            User* user = userManager.createUser(username_str);
            if (user) {
                user->setRank(std::stoi(rank_str));
                user->setActivityScore(std::stod(activityScore_str));
            }
        }
        inFile.close();
        std::cout << "User data loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for loading user data: " << filename << std::endl;
    }
}

void DataManager::saveAccountData(const Account& account, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        // Save current balance
        outFile << "BALANCE:" << account.getBalance() << "\n";

        // Save savings data
        outFile << "SAVINGS:" << account.getSavings().toString() << "\n";

        outFile.close();
        std::cout << "Account data saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for saving account data: " << filename << std::endl;
    }
}

void DataManager::loadAccountData(Account& account, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string type_prefix;
            std::getline(ss, type_prefix, ':');

            if (type_prefix == "BALANCE") {
                std::string balance_str;
                std::getline(ss, balance_str);
                account.setBalance(std::stod(balance_str));
            } else if (type_prefix == "SAVINGS") {
                std::string savings_data;
                std::getline(ss, savings_data);
                std::stringstream savings_ss(savings_data);
                std::string currentSavings_str, targetAmount_str, targetDate_str, lastInstallmentDate_str, isTargetBased_str;
                std::getline(savings_ss, currentSavings_str, ',');
                std::getline(savings_ss, targetAmount_str, ',');
                std::getline(savings_ss, targetDate_str, ',');
                std::getline(savings_ss, lastInstallmentDate_str, ',');
                std::getline(savings_ss, isTargetBased_str);

                account.setSavingsState(
                    std::stod(currentSavings_str),
                    std::stod(targetAmount_str),
                    stringToTimePoint(targetDate_str),
                    stringToTimePoint(lastInstallmentDate_str),
                    (isTargetBased_str == "1")
                );
            }
        }
        inFile.close();
        std::cout << "Account data loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for loading account data: " << filename << std::endl;
    }
}