#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    int rank;
    double activityScore;

public:
    User(const std::string& username);
    std::string getUsername() const;
    int getRank() const;
    void updateRank(int rank);
    double getActivityScore() const;
    void addActivityScore(double score);
    void setRank(int rank);
    void setActivityScore(double score);
};

#endif // USER_H
