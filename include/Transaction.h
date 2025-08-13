#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <chrono>

class Transaction {
protected:
    double amount;
    std::string description;
    std::chrono::system_clock::time_point date;

public:
    Transaction(double amount, const std::string& description);
    virtual ~Transaction() = default;

    double getAmount() const;
    std::string getDescription() const;
    std::chrono::system_clock::time_point getDate() const;

    virtual std::string getType() const = 0;
    virtual std::string toString() const = 0;
};

class Income : public Transaction {
private:
    bool isFixed;

public:
    Income(double amount, const std::string& description, bool isFixed);
    std::string getType() const override;
    bool isFixedSource() const;
    std::string toString() const override;
};

class Expense : public Transaction {
private:
    std::string category;

public:
    Expense(double amount, const std::string& description, const std::string& category);
    std::string getType() const override;
    std::string getCategory() const;
    std::string toString() const override;
};

#endif // TRANSACTION_H
