#include <iostream>
#include "helper.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include <chrono>
#include <iostream>
#include <filesystem>

int main(){
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    std::string input, filename;
    std::cout << "Would you like to sort Test or Train?" << std::endl;
    std::cin >> input;
    if (input == "test" or input== "Test") {
        filename = "data/test.csv";
    }
    else if (input == "train" or input== "Train") {
        filename = "data/train.csv";
    }
    else {
        std::cout << "Please enter a valid input." << std::endl;
    }
    try {
        //std::string filename = "data/test.csv";
        std::vector<Review> review = loadingDataset(filename);
        std::cout << "Attempting to open file: " << filename << std::endl;

        if(review.empty()){
            std::cerr << "No data to process." <<std::endl;
            return 1;
        }
        //quick sort implementation
        auto quickReview = review;
        auto start = std::chrono::high_resolution_clock ::now();
        quickSort(quickReview, 0, quickReview.size() - 1);
        auto end = std::chrono::high_resolution_clock ::now();
        std::cout << "Quick Sort Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms" << std::endl;
        saveTheSortedData(quickReview, "results/sorted_data_quick.csv");

        //merge sort implementation
        auto mergeReview = review;
        start = std::chrono::high_resolution_clock::now();
        mergeSort(mergeReview, 0, mergeReview.size() - 1);
        end = std::chrono::high_resolution_clock ::now();
        std::cout << "Merge Sort Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << "ms" << std::endl;
        saveTheSortedData(mergeReview, "results/sorted_data_merge.csv");
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}