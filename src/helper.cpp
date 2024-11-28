//
// Created by maria on 11/25/2024.
//
#include "helper.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Review> loadingDataset(const std::string &filename){
    std::vector<Review> review;
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr <<"Error opening file: " << filename <<std::endl;
        return review;
    }
    std::string line;
    while(getline(file, line)){
        if (line.empty()) continue;
        //std::cout << "Reading Line: " << line << std::endl;
        std::stringstream  ss(line);
        std::string polarity, text;

        getline(ss, polarity, ',');
        //std::cout << "Polarity: " << polarity << std::endl;
        polarity.erase(polarity.begin());
        while (!std::isdigit(polarity.back())) polarity.pop_back();

        //std::cout << polarity << std::endl;
        getline(ss, text, '\n');
        //std::cout << "Text: " << text << std::endl;
        try {
            review.push_back({std::stoi(polarity),text});
        } catch (const std::invalid_argument& e){
            std::cerr << "Invalid polarity value: " << polarity << std::endl;
            continue;
        }
    }
    file.close();
    return review;
}

void saveTheSortedData(const std::vector<Review> &review, const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for(const auto &reviews : review){
        file << reviews.polarity << ", " << reviews.text <<"\n";
    }
    file.close();
}
bool compare(const Review &a, const Review &b){
    if(a.polarity == b.polarity){
        //sort by polarity length if they are equal
        return a.text.length() < b.text.length();
    }
    //sort by polarity
    return a.polarity < b.polarity;
}
