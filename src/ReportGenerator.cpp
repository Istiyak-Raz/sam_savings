#include "ReportGenerator.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <numeric> // For std::accumulate

void ReportGenerator::generateMonthlyReport(const Account& account, int year, int month) {
    std::cout << "\n--- Monthly Report (" << month << "/" << year << ") ---" << std::endl;

    double totalIncome = 0.0;
    double totalExpense = 0.0;

    std::cout << "\n--- Income ---" << std::endl;
    // Filter and display income for the specified month/year
    for (const auto& t : account.getTransactions()) {
        if (t->getType() == "Income") {
            std::time_t tt = std::chrono::system_clock::to_time_t(t->getDate());
            std::tm* ltm = std::localtime(&tt);
            if (ltm->tm_year + 1900 == year && ltm->tm_mon + 1 == month) {
                std::cout << "Date: " << std::put_time(ltm, "%F %T")
                          << ", Amount: " << std::fixed << std::setprecision(2) << t->getAmount()
                          << ", Description: " << t->getDescription() << std::endl;
                totalIncome += t->getAmount();
            }
        }
    }
    std::cout << "Total Income for " << month << "/" << year << ": $" << std::fixed << std::setprecision(2) << totalIncome << std::endl;


    std::cout << "\n--- Expenses ---" << std::endl;
    // Filter and display expenses for the specified month/year
    for (const auto& t : account.getTransactions()) {
        if (t->getType() == "Expense") {
            std::time_t tt = std::chrono::system_clock::to_time_t(t->getDate());
            std::tm* ltm = std::localtime(&tt);
            if (ltm->tm_year + 1900 == year && ltm->tm_mon + 1 == month) {
                std::cout << "Date: " << std::put_time(ltm, "%F %T")
                          << ", Amount: " << std::fixed << std::setprecision(2) << t->getAmount()
                          << ", Description: " << t->getDescription() << std::endl;
                totalExpense += t->getAmount();
            }
        }
    }
    std::cout << "Total Expenses for " << month << "/" << year << ": $" << std::fixed << std::setprecision(2) << totalExpense << std::endl;


    std::cout << "\n--- Savings ---" << std::endl;
    std::cout << "Current Total Savings: $" << std::fixed << std::setprecision(2) << account.getCurrentSavings() << std::endl;
    // Note: Detailed savings transactions are not stored in Account's transaction list,
    // so this would require a separate mechanism if needed for monthly reports.


    std::cout << "\n--- Loans ---" << std::endl;
    account.displayLoans(); // Re-use existing display for loans


    std::cout << "\n--- Report Analysis ---" << std::endl;
    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
    std::cout << "Total Income (this month): $" << std::fixed << std::setprecision(2) << totalIncome << std::endl;
    std::cout << "Total Expenses (this month): $" << std::fixed << std::setprecision(2) << totalExpense << std::endl;
    std::cout << "Net Flow (this month): $" << std::fixed << std::setprecision(2) << totalIncome - totalExpense << std::endl;
    std::cout << "--------------------------" << std::endl;
}