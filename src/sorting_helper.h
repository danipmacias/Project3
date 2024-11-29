//
// Created by Daniela Macias on 11/28/24.
//

#ifndef SORTING_HELPER_H
#define SORTING_HELPER_H

#include <QObject>
#include <vector>
#include "helper.h"
#include "quick_sort.h"
#include "merge_sort.h"

class SortingHelper : public QObject {
    Q_OBJECT

public:
    explicit SortingHelper(const QString &filename, QObject *parent = nullptr)
        : QObject(parent), filename(filename) {}

signals:
    void quickSortProgressUpdated(int value);
    void quickSortTimeUpdated(const QString &time);
    void mergeSortProgressUpdated(int value);
    void mergeSortTimeUpdated(const QString &time);
    void finished();

public slots:
    void process() {
        try {
            std::vector<Review> reviews = loadingDataset(filename.toStdString());
            if (reviews.empty()) {
                emit quickSortTimeUpdated("Error: No data");
                emit mergeSortTimeUpdated("Error: No data");
                emit finished();
                return;
            }

            int totalSize = static_cast<int>(reviews.size());

            // Quick Sort
            auto quickReviews = reviews;
            emit quickSortProgressUpdated(0);
            auto quickStart = std::chrono::high_resolution_clock::now();
            // Will update progress bar as the program compiles
            quickSort(quickReviews, 0, totalSize-1, [&](int progress){emit quickSortProgressUpdated(progress);}, totalSize);
            auto quickEnd = std::chrono::high_resolution_clock::now();
            auto quickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(quickEnd - quickStart).count();
            emit quickSortProgressUpdated(100);
            emit quickSortTimeUpdated(QString::number(quickDuration) + " ms");
            saveTheSortedData(quickReviews, "results/sorted_data_quick.csv");

            // Merge Sort
            auto mergeReviews = reviews;
            emit mergeSortProgressUpdated(0);
            auto mergeStart = std::chrono::high_resolution_clock::now();
            // Will update progress bar as the program compiles
            mergeSort(mergeReviews, 0, totalSize - 1, [&](int progress){emit mergeSortProgressUpdated(progress);}, totalSize);

            auto mergeEnd = std::chrono::high_resolution_clock::now();
            auto mergeDuration = std::chrono::duration_cast<std::chrono::milliseconds>(mergeEnd - mergeStart).count();
            emit mergeSortProgressUpdated(100);
            emit mergeSortTimeUpdated(QString::number(mergeDuration) + " ms");
            saveTheSortedData(mergeReviews, "results/sorted_data_merge.csv");

        } catch (const std::exception &e) {
            emit quickSortTimeUpdated(QString("Error").arg(e.what()));
            emit mergeSortTimeUpdated(QString("Error").arg(e.what()));
        }

        emit finished();
    }

private:
    QString filename;
};

#endif // SORTING_HELPER_H
