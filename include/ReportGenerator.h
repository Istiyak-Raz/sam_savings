#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>
#include <vector>
#include <chrono>
#include "Account.h" // To access account data

class ReportGenerator {
public:
    static void generateMonthlyReport(const Account& account, int year, int month);
};

#endif // REPORT_GENERATOR_H
