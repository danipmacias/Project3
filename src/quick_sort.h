//
// Created by maria on 11/25/2024.
//

#ifndef UNTITLED_QUICK_SORT_H
#define UNTITLED_QUICK_SORT_H

#include <vector>
#include "helper.h"
#include <functional>

void quickSort(std::vector<Review> &review, int low, int high, const std::function<void(int)> &progressCallback, int totalSize);

#endif //UNTITLED_QUICK_SORT_H
