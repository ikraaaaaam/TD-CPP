#pragma once

#include <vector>
#include <iostream>

using namespace std;

class SearchingAlgorithm {
protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;
    virtual int search(const vector<int>& vec, int target) = 0;
    void displaySearchResults(ostream& os, int result, int target);
};


