#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <chrono>

class Loan {
private:
    double amount;
    std::string reason;
    std::string friendName;
    std::chrono::system_clock::time_point dueDate;
    bool isRepaid;

public:
    Loan(double amount, const std::string& reason, const std::string& friendName, const std::chrono::system_clock::time_point& dueDate);

    double getAmount() const;
    std::string getReason() const;
    std::string getFriendName() const;
    std::chrono::system_clock::time_point getDueDate() const;
    bool getIsRepaid() const;
    void markAsRepaid();
    std::string toString() const;
};

#endif // LOAN_H
