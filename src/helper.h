//
// Created by maria on 11/25/2024.
//

#ifndef UNTITLED_HELPER_H
#define UNTITLED_HELPER_H
#include <string>
#include <vector>

struct Review{
    // 1 = negative -- 2 = positive
    int polarity;
    // body of the review
    std::string text;
};

std::vector<Review> loadingDataset(const std::string &filename);
void saveTheSortedData(const std::vector<Review> &review, const std::string &filename);
bool compare(const Review &a, const Review &b);

#endif //UNTITLED_HELPER_H
