//
// Created by maria on 11/25/2024.
//

#ifndef UNTITLED_QUICK_SORT_H
#define UNTITLED_QUICK_SORT_H

#include <vector>
#include "helper.h"
#include <functional>

void quickSort(std::vector<Review> &review, int low, int high, std::function<void(int)> progressCall, int totalSize);

#endif //UNTITLED_QUICK_SORT_H
//void quickSort(std::vector<Review> &review, int low, int high);
