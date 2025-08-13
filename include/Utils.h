#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <ctime>

// Helper function to convert time_point to string
inline std::string timePointToString(const std::chrono::system_clock::time_point& tp) {
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&tt);
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Helper function to convert string to time_point
inline std::chrono::system_clock::time_point stringToTimePoint(const std::string& s) {
    std::tm tm = {};
    std::stringstream ss(s);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

#endif // UTILS_H
