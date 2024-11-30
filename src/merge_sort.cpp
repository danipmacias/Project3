//
// Created by maria on 11/25/2024.
//
#include "merge_sort.h"



void merge(std::vector<Review> &review, int left, int mid, int right){
    std::vector<Review> leftP(review.begin() + left, review.begin() + mid + 1);
    std::vector<Review> rightP(review.begin() + mid + 1, review.begin() + right + 1);
    int i = 0 , j =0, k = left;
    while(i < leftP.size() && j < rightP.size()){
        if(compare(leftP[i], rightP[j])){
            review[k++] = leftP[i++];
        }else{
            review[k++] = rightP[j++];
        }
    }
    while (i < leftP.size()){
        review[k++] = leftP[i++];
    }
    while (j < rightP.size()){
        review[k++] = rightP[j++];
    }
}

// Adding "function" so the progress bar dynamically updates its progress as the program is running
void mergeSort(std::vector<Review> &review, int left, int right, const std::function<void(int)> &progressCallback, int totalSize){
    if( left < right) {
        // Percentage of progress that will be reported back to progress bar
        int progress = right * 100 / totalSize;
        if (progress % 10 == 0) {
            progressCallback(progress);
        }

        int mid = left + (right - left) / 2;

        mergeSort(review, left, mid, progressCallback, totalSize);
        mergeSort(review, mid + 1, right, progressCallback, totalSize);
        merge(review, left, mid, right);

    }
}