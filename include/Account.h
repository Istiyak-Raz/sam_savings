#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include "Loan.h"
#include "Savings.h"
#include "Wishlist.h"
#include "WishlistItem.h"
#include <vector>
#include <memory>

class Account {
private:
    double currentBalance;
    std::vector<std::unique_ptr<Transaction>> transactions;
    std::vector<Loan> loans;
    Savings savings;
    Wishlist wishlist;

public:
    Account();
    double getBalance() const;
    void setBalance(double balance);
    void addTransaction(std::unique_ptr<Transaction> transaction);
    void displayTransactions() const;
    void requestLoan(double amount, const std::string& reason, const std::string& friendName, const std::chrono::system_clock::time_point& dueDate);
    void repayLoan(int loanIndex);
    void displayLoans() const;
    void addSavings(double amount);
    void setSavingsTarget(double amount, const std::chrono::system_clock::time_point& date);
    void autoSaveSurplus(double dailyBudgetMin);
    double getCurrentSavings() const;
    void addWishlistItem(const WishlistItem& item);
    void displayWishlist() const;
    const std::vector<std::unique_ptr<Transaction>>& getTransactions() const;
    const std::vector<Loan>& getLoans() const;
    const Savings& getSavings() const;
    const Wishlist& getWishlist() const;
    void setSavingsState(double currentSavings, double targetAmount, const std::chrono::system_clock::time_point& targetDate, const std::chrono::system_clock::time_point& lastInstallmentDate, bool isTargetBased);
};

#endif // ACCOUNT_H
