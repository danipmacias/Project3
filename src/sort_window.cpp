//
// Created by Daniela Macias on 11/28/24.
//

#include "sort_window.h"
#include "helper.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include <QThread>
#include <QLabel>
#include <QVBoxLayout>
#include <chrono>

SortWindow::SortWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Sorting Application");

    //int progress = 0;
    // Adding buttons
    testButton = new QPushButton("Sort test.csv", this);
    trainButton = new QPushButton("Sort train.csv", this);

    // Progress bar
    quickSortProgressBar = new QProgressBar(this);
    quickSortProgressBar->setRange(0, 100);
    quickSortProgressBar->setValue(0);

    // Label for Progress bar
    quickSortStatusLabel = new QLabel("Quick Sort: ", this);
    quickSortTimeLabel = new QLabel("Time: 0 ms", this);

    mergeSortProgressBar = new QProgressBar(this);
    mergeSortProgressBar->setRange(0, 100);
    mergeSortProgressBar->setValue(0);

    mergeSortStatusLabel = new QLabel("Merge Sort: ", this);
    mergeSortTimeLabel = new QLabel("Time: 0 ms", this);

    // Ordering layout of window
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(testButton);
    layout->addWidget(trainButton);
    layout->addWidget(quickSortStatusLabel);
    layout->addWidget(quickSortProgressBar);
    layout->addWidget(quickSortTimeLabel);
    layout->addWidget(mergeSortStatusLabel);
    layout->addWidget(mergeSortProgressBar);
    layout->addWidget(mergeSortTimeLabel);
    setLayout(layout);

    // Connecting button press to call for sorting of a dataset
    connect(testButton, &QPushButton::clicked, this, &SortWindow::openSortWindowForTest);
    connect(trainButton, &QPushButton::clicked, this, &SortWindow::openSortWindowForTrain);

}

void SortWindow::startSorting(const QString &filename) {
    // Create a worker and a thread
    SortingHelper quickWorker(filename);

    connect(&quickWorker, &SortingHelper::quickSortProgressUpdated, this, &SortWindow::updateQuickSortProgress);
    connect(&quickWorker, &SortingHelper::quickSortTimeUpdated, this, &SortWindow::updateQuickSortTime);

    quickWorker.quickProcess();

    SortingHelper mergeWorker(filename);
    connect(&mergeWorker, &SortingHelper::mergeSortProgressUpdated, this, &SortWindow::updateMergeSortProgress);
    connect(&mergeWorker, &SortingHelper::mergeSortTimeUpdated, this, &SortWindow::updateMergeSortTime);

    mergeWorker.mergeProcess();

}
void SortWindow::updateQuickSortProgress(int value) {
    quickSortProgressBar->setValue(value);
}

void SortWindow::updateMergeSortProgress(int value) {
    mergeSortProgressBar->setValue(value);
}

void SortWindow::updateQuickSortTime(const QString &time) {
    quickSortTimeLabel->setText("Time: " + time);
}

void SortWindow::updateMergeSortTime(const QString &time) {
    mergeSortTimeLabel->setText("Time: " + time);
}

void SortWindow::openSortWindowForTest() {
    updateMergeSortProgress(0);
    updateQuickSortProgress(0);
    updateQuickSortTime("0 ms");
    updateMergeSortTime("0 ms");
    startSorting("data/test.csv");
}
void SortWindow::openSortWindowForTrain() {
    updateMergeSortProgress(0);
    updateQuickSortProgress(0);
    updateQuickSortTime("0 ms");
    updateMergeSortTime("0 ms");
    startSorting("data/train.csv");
}