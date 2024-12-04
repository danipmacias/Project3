//
// Created by maria on 11/25/2024.
//
#include "quick_sort.h"
#include <functional>
#include "sort_window.h"

int median(std::vector<Review> &review, int low, int high) {
    int mid = low + (high - low) / 2;
    if (review[low] > review[mid])
        std::swap(review[low],review[mid]);
    if (review[low] > review[high])
        std::swap(review[low],review[high]);
    if (review[mid] > review[high])
        std::swap(review[mid],review[high]);
    return mid;
}


int partition(std::vector<Review> &review, int low, int high){
    int index = median(review, low, high);
    std::swap(review[index],review[high]);
    Review pivot = review[high];
    int i = low - 1;
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
void quickSort(std::vector<Review> &review, int low, int high, std::function<void(int)> progressCall, int totalSize){
    if (low >= high) return;

    if(low < high){
        int progress = ((totalSize - (high - low)) * 100) / totalSize;
        if (progress % 10 == 5) {
            progressCall(progress);
        }

        int pivot = partition(review, low, high);

        //Percentage of progress that will be reported back to progress bar

        quickSort(review, low, pivot - 1, progressCall, totalSize);
        quickSort(review, pivot + 1, high, progressCall, totalSize);
    }
}
// void quickSort(std::vector<Review> &review, int low, int high){
//     if (low >= high) return;
//
//     if(low < high){
//         int pivot = partition(review, low, high);
//
//         //Percentage of progress that will be reported back to progress bar
//
//         quickSort(review, low, pivot - 1);
//         quickSort(review, pivot + 1, high);
//     }
// }