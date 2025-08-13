#ifndef SAVINGS_H
#define SAVINGS_H

#include <string>
#include <chrono>

class Savings {
private:
    double currentSavings;
    double targetAmount;
    std::chrono::system_clock::time_point targetDate;
    std::chrono::system_clock::time_point lastInstallmentDate;
    bool isTargetBased;

public:
    Savings();

    double getCurrentSavings() const;
    void addSavings(double amount);

    // For target-based savings
    void setTarget(double amount, const std::chrono::system_clock::time_point& date);
    bool isTargetSet() const;
    double getTargetAmount() const;
    std::chrono::system_clock::time_point getTargetDate() const;
    std::chrono::system_clock::time_point getLastInstallmentDate() const;
    void updateLastInstallmentDate();
    double getProgressPercentage() const;
    std::string toString() const;

    // New setters for DataManager
    void setCurrentSavings(double amount);
    void setTargetAmount(double amount);
    void setTargetDate(const std::chrono::system_clock::time_point& date);
    void setLastInstallmentDate(const std::chrono::system_clock::time_point& date);
    void setIsTargetBased(bool isTargetBased);
};

#endif // SAVINGS_H
