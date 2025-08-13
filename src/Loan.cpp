#include "Loan.h"
#include "Utils.h" // Include the new utility header

// Removed local definition of timePointToString

Loan::Loan(double amount, const std::string& reason, const std::string& friendName, const std::chrono::system_clock::time_point& dueDate)
    : amount(amount), reason(reason), friendName(friendName), dueDate(dueDate), isRepaid(false) {}

double Loan::getAmount() const {
    return amount;
}

std::string Loan::getReason() const {
    return reason;
}

std::string Loan::getFriendName() const {
    return friendName;
}

std::chrono::system_clock::time_point Loan::getDueDate() const {
    return dueDate;
}

bool Loan::getIsRepaid() const {
    return isRepaid;
}

void Loan::markAsRepaid() {
    isRepaid = true;
}

std::string Loan::toString() const {
    return std::to_string(amount) + "," + reason + "," + friendName + "," + timePointToString(dueDate) + "," + std::to_string(isRepaid);
}
