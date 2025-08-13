#include "Account.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Savings.h"
#include "Wishlist.h"

Account::Account() : currentBalance(0.0) {}

double Account::getBalance() const {
    return currentBalance;
}

void Account::addTransaction(std::unique_ptr<Transaction> transaction) {
    if (transaction->getType() == "Income") {
        currentBalance += transaction->getAmount();
    } else if (transaction->getType() == "Expense") {
        currentBalance -= transaction->getAmount();
    }
    transactions.push_back(std::move(transaction));
}

void Account::displayTransactions() const {
    std::cout << "--- Transaction History ---" << std::endl;
    for (const auto& t : transactions) {
        std::time_t tt = std::chrono::system_clock::to_time_t(t->getDate());
        std::cout << "Date: " << std::put_time(std::localtime(&tt), "%F %T") << std::endl;
        std::cout << "  Type: " << t->getType()
                  << ", Amount: " << std::fixed << std::setprecision(2) << t->getAmount()
                  << ", Description: " << t->getDescription() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

void Account::requestLoan(double amount, const std::string& reason, const std::string& friendName, const std::chrono::system_clock::time_point& dueDate) {
    loans.emplace_back(amount, reason, friendName, dueDate);
    currentBalance += amount;
    std::cout << "Loan of $" << amount << " requested successfully from " << friendName << ". Current balance: $" << currentBalance << std::endl;
}

void Account::repayLoan(int loanIndex) {
    if (loanIndex >= 0 && loanIndex < loans.size()) {
        Loan& loan = loans[loanIndex];
        if (!loan.getIsRepaid()) {
            if (currentBalance >= loan.getAmount()) {
                currentBalance -= loan.getAmount();
                loan.markAsRepaid();
                std::cout << "Loan of $" << loan.getAmount() << " repaid successfully. Current balance: $" << currentBalance << std::endl;
            } else {
                std::cout << "Insufficient balance to repay the loan." << std::endl;
            }
        } else {
            std::cout << "Loan already repaid." << std::endl;
        }
    } else {
        std::cout << "Invalid loan index." << std::endl;
    }
}

void Account::displayLoans() const {
    std::cout << "--- Outstanding Loans ---" << std::endl;
    if (loans.empty()) {
        std::cout << "No outstanding loans." << std::endl;
    } else {
        for (size_t i = 0; i < loans.size(); ++i) {
            const Loan& loan = loans[i];
            std::time_t tt = std::chrono::system_clock::to_time_t(loan.getDueDate());
            std::cout << "Loan " << i << ": $" << std::fixed << std::setprecision(2) << loan.getAmount()
                      << " from " << loan.getFriendName()
                      << " (Reason: " << loan.getReason()
                      << ", Due: " << std::put_time(std::localtime(&tt), "%F %T")
                      << ", Repaid: " << (loan.getIsRepaid() ? "Yes" : "No") << ")" << std::endl;
        }
    }
    std::cout << "-------------------------" << std::endl;
}

void Account::addSavings(double amount) {
    if (currentBalance >= amount) {
        currentBalance -= amount;
        savings.addSavings(amount);
    } else {
        std::cout << "Insufficient balance to add to savings." << std::endl;
    }
}

void Account::setSavingsTarget(double amount, const std::chrono::system_clock::time_point& date) {
    savings.setTarget(amount, date);
}

void Account::autoSaveSurplus(double dailyBudgetMin) {
    if (currentBalance > dailyBudgetMin) {
        double surplus = currentBalance - dailyBudgetMin;
        currentBalance -= surplus;
        savings.addSavings(surplus);
        std::cout << "Automatically saved $" << surplus << " as surplus. Current balance: $" << currentBalance << std::endl;
    } else {
        std::cout << "No surplus to save." << std::endl;
    }
}

double Account::getCurrentSavings() const {
    return savings.getCurrentSavings();
}

void Account::addWishlistItem(const WishlistItem& item) {
    wishlist.addItem(item);
}

void Account::displayWishlist() const {
    wishlist.displayWishlist(savings.getCurrentSavings());
}

const std::vector<std::unique_ptr<Transaction>>& Account::getTransactions() const {
    return transactions;
}

const std::vector<Loan>& Account::getLoans() const {
    return loans;
}

const Savings& Account::getSavings() const {
    return savings;
}

const Wishlist& Account::getWishlist() const {
    return wishlist;
}

void Account::setBalance(double balance) {
    this->currentBalance = balance;
}

void Account::setSavingsState(double currentSavings, double targetAmount, const std::chrono::system_clock::time_point& targetDate, const std::chrono::system_clock::time_point& lastInstallmentDate, bool isTargetBased) {
    savings.setCurrentSavings(currentSavings);
    savings.setTargetAmount(targetAmount);
    savings.setTargetDate(targetDate);
    savings.setLastInstallmentDate(lastInstallmentDate);
    savings.setIsTargetBased(isTargetBased);
}
