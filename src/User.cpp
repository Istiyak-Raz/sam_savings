#include "User.h"

User::User(const std::string& username) : username(username), rank(0), activityScore(0.0) {
}

std::string User::getUsername() const {
    return username;
}

int User::getRank() const {
    return rank;
}

void User::updateRank(int rank) {
    this->rank = rank;
}

double User::getActivityScore() const {
    return activityScore;
}

void User::addActivityScore(double score) {
    activityScore += score;
}

void User::setRank(int rank) {
    this->rank = rank;
}

void User::setActivityScore(double score) {
    this->activityScore = score;
}
