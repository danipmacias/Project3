//
// Created by maria on 11/25/2024.
//
#include "quick_sort.h"
#include <functional>

int partition(std::vector<Review> &review, int low, int high){
    Review pivot = review[high];
    int i = low -1;
    for(int j = low; j < high; ++j){
        if(compare(review[j], pivot)) {
            ++i;
            std::swap(review[i], review[j]);
        }
    }
    std::swap(review[i+1], review[high]);
    return i + 1;
}

// Adding "functions" in order to receive the progress of sorted data to
// be able to be dynamic in window
void quickSort(std::vector<Review> &review, int low, int high, const std::function<void(int)> &progressCallback, int totalSize){
    if(low < high){
        int pivot = partition(review, low, high);

        // Percentage of progress that will be reported back to progress bar
        int progress = pivot * 100 / totalSize;
        if (progress % 10 == 0) {
            progressCallback(progress);
        }

        quickSort(review, low, pivot - 1, progressCallback, totalSize);
        quickSort(review, pivot + 1, high, progressCallback, totalSize);

    }
}