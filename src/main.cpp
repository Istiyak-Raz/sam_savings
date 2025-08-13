#include <iostream>
#include <memory>
#include <chrono>
#include "User.h"
#include "Account.h"
#include "Transaction.h"
#include "Loan.h"
#include "Savings.h"
#include "WishlistItem.h"
#include "Wishlist.h"
#include "NotificationManager.h"

int main()
{
    std::cout << "Welcome to Smart Savings!" << std::endl;

    // Create a user
    User currentUser("StudentUser");
    std::cout << "Logged in as: " << currentUser.getUsername() << std::endl;

    // Create an account
    Account studentAccount;
    std::cout << "Initial Balance: $" << studentAccount.getBalance() << std::endl;

    // Add some income
    studentAccount.addTransaction(std::make_unique<Income>(1000.0, "Financial Support", true));
    studentAccount.addTransaction(std::make_unique<Income>(200.0, "Part-time Job", true));
    studentAccount.addTransaction(std::make_unique<Income>(50.0, "Gift from Grandma", false));

    std::cout << "Balance after income: $" << studentAccount.getBalance() << std::endl;

    // Add some expenses
    studentAccount.addTransaction(std::make_unique<Expense>(150.0, "Monthly Rent", "Accommodation"));
    studentAccount.addTransaction(std::make_unique<Expense>(30.0, "Groceries", "Irregular"));
    studentAccount.addTransaction(std::make_unique<Expense>(10.0, "Daily Meal", "Daily"));

    std::cout << "Balance after expenses: $" << studentAccount.getBalance() << std::endl;

    // Display transaction history
    studentAccount.displayTransactions();

    // --- Loan Functionality ---
    std::cout << "\n--- Testing Loan Functionality ---" << std::endl;

    // Request a loan
    auto loanDueDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 30); // 30 days from now
    studentAccount.requestLoan(500.0, "Emergency medical bill", "Friend A", loanDueDate);
    studentAccount.requestLoan(100.0, "New textbook", "Friend B", loanDueDate);

    // Display loans
    studentAccount.displayLoans();

    // Repay a loan
    studentAccount.repayLoan(0); // Repay the first loan

    // Display loans again to show repaid status
    studentAccount.displayLoans();

    // --- Savings Functionality ---
    std::cout << "\n--- Testing Savings Functionality ---" << std::endl;

    // Add some amount to savings directly
    studentAccount.addSavings(50.0);
    std::cout << "Current Savings: $" << studentAccount.getCurrentSavings() << std::endl;

    // Set a savings target
    auto targetDate = std::chrono::system_clock::now() + std::chrono::hours(24 * 60); // 60 days from now
    studentAccount.setSavingsTarget(500.0, targetDate);

    // Automatically save surplus
    studentAccount.autoSaveSurplus(100.0); // Assuming a daily budget minimum of $100
    std::cout << "Current Savings: $" << studentAccount.getCurrentSavings() << std::endl;

    // --- Wishlist Functionality ---
    std::cout << "\n--- Testing Wishlist Functionality ---" << std::endl;

    // Add some wishlist items
    auto itemDeadline1 = std::chrono::system_clock::now() + std::chrono::hours(24 * 90); // 90 days from now
    studentAccount.addWishlistItem(WishlistItem("New Laptop", 1200.0, itemDeadline1, "For studies and light gaming."));

    auto itemDeadline2 = std::chrono::system_clock::now() + std::chrono::hours(24 * 180); // 180 days from now
    studentAccount.addWishlistItem(WishlistItem("Travel to Japan", 2500.0, itemDeadline2, "Dream vacation after graduation."));

    // Display the wishlist
    studentAccount.displayWishlist();

    // --- Notification Functionality ---
    std::cout << "\n--- Testing Notification Functionality ---" << std::endl;
    NotificationManager::displayDailyNotifications(studentAccount);
    NotificationManager::displayWishlistNotifications(studentAccount);

    std::cout << "Final Balance: $" << studentAccount.getBalance() << std::endl;

    return 0;
}