//
// Created by Daniela Macias on 11/28/24.
//

#ifndef SORT_WINDOW_H
#define SORT_WINDOW_H

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "sorting_helper.h"

class SortWindow : public QWidget {
    Q_OBJECT

public:
    explicit SortWindow(QWidget *parent = nullptr);
    void setProgress(int value);
    void setSortingStatus(const QString& text);
    void setResult(const QString &text);

private:
    QProgressBar *quickSortProgressBar;
    QProgressBar *mergeSortProgressBar;
    QLabel *quickSortStatusLabel;
    QLabel *quickSortTimeLabel;
    QLabel *mergeSortStatusLabel;
    QLabel *mergeSortTimeLabel;
    QPushButton *testButton;
    QPushButton *trainButton;


public slots:
    void startSorting(const QString& filename);

    void updateQuickSortProgress(int value);

    void updateMergeSortProgress(int value);

    void updateQuickSortTime(const QString &time);

    void updateMergeSortTime(const QString &time);

    void openSortWindowForTest();

    void openSortWindowForTrain();


};

#endif // SORT_WINDOW_H

