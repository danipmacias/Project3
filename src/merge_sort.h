//
// Created by maria on 11/25/2024.
//

#ifndef UNTITLED_MERGE_SORT_H
#define UNTITLED_MERGE_SORT_H

#include <vector>
#include "helper.h"
#include <functional>

void mergeSort(std::vector<Review> &review, int left , int right, const std::function<void(int)> &progressCallback, int totalSize);

#endif //UNTITLED_MERGE_SORT_H
