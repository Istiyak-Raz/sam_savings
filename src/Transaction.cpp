#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Utils.h" // Include the new utility header

// Removed local definition of timePointToString

// Transaction base class
Transaction::Transaction(double amount, const std::string& description)
    : amount(amount), description(description), date(std::chrono::system_clock::now()) {}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDescription() const {
    return description;
}

std::chrono::system_clock::time_point Transaction::getDate() const {
    return date;
}

// Income derived class
Income::Income(double amount, const std::string& description, bool isFixed)
    : Transaction(amount, description), isFixed(isFixed) {}

std::string Income::getType() const {
    return "Income";
}

bool Income::isFixedSource() const {
    return isFixed;
}

std::string Income::toString() const {
    return "Income," + std::to_string(amount) + "," + description + "," + timePointToString(date) + "," + std::to_string(isFixed);
}

// Expense derived class
Expense::Expense(double amount, const std::string& description, const std::string& category)
    : Transaction(amount, description), category(category) {}

std::string Expense::getType() const {
    return "Expense";
}

std::string Expense::getCategory() const {
    return category;
}

std::string Expense::toString() const {
    return "Expense," + std::to_string(amount) + "," + description + "," + timePointToString(date) + "," + category;
}
