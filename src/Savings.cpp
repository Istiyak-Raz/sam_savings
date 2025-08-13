#include "Savings.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Utils.h" // Include the new utility header

// Removed local definition of timePointToString

Savings::Savings() : currentSavings(0.0), targetAmount(0.0), isTargetBased(false) {}

double Savings::getCurrentSavings() const {
    return currentSavings;
}

void Savings::addSavings(double amount) {
    if (amount > 0) {
        currentSavings += amount;
        std::cout << "Added $" << amount << " to savings. Current savings: $" << currentSavings << std::endl;
    }
}

void Savings::setTarget(double amount, const std::chrono::system_clock::time_point& date) {
    if (amount > 0) {
        targetAmount = amount;
        targetDate = date;
        isTargetBased = true;
        lastInstallmentDate = std::chrono::system_clock::now(); // Initialize with current time
        std::time_t tt = std::chrono::system_clock::to_time_t(targetDate);
        std::cout << "Savings target set: $" << targetAmount << " by " << std::put_time(std::localtime(&tt), "%F %T") << std::endl;
    }
}

bool Savings::isTargetSet() const {
    return isTargetBased;
}

double Savings::getTargetAmount() const {
    return targetAmount;
}

std::chrono::system_clock::time_point Savings::getTargetDate() const {
    return targetDate;
}

std::chrono::system_clock::time_point Savings::getLastInstallmentDate() const {
    return lastInstallmentDate;
}

void Savings::updateLastInstallmentDate() {
    lastInstallmentDate = std::chrono::system_clock::now();
}

double Savings::getProgressPercentage() const {
    if (isTargetBased && targetAmount > 0) {
        return (currentSavings / targetAmount) * 100.0;
    }
    return 0.0;
}

std::string Savings::toString() const {
    return std::to_string(currentSavings) + "," +
           std::to_string(targetAmount) + "," +
           timePointToString(targetDate) + "," +
           timePointToString(lastInstallmentDate) + "," +
           std::to_string(isTargetBased);
}

void Savings::setCurrentSavings(double amount) {
    this->currentSavings = amount;
}

void Savings::setTargetAmount(double amount) {
    this->targetAmount = amount;
}

void Savings::setTargetDate(const std::chrono::system_clock::time_point& date) {
    this->targetDate = date;
}

void Savings::setLastInstallmentDate(const std::chrono::system_clock::time_point& date) {
    this->lastInstallmentDate = date;
}

void Savings::setIsTargetBased(bool isTargetBased) {
    this->isTargetBased = isTargetBased;
}