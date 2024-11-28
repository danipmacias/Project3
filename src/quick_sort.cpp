//
// Created by maria on 11/25/2024.
//
#include "quick_sort.h"

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

void quickSort(std::vector<Review> &review, int low, int high){
    if(low < high){
        int pivot = partition(review, low, high);
        quickSort(review, low, pivot - 1);
        quickSort(review, pivot + 1, high);
    }
}