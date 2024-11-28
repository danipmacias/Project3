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

void mergeSort(std::vector<Review> &review, int left, int right){
    if( left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(review, left, mid);
        mergeSort(review, mid + 1, right);
        merge(review, left, mid, right);
    }
}