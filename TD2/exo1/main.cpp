#include "search.h"
#include <iostream>
#include <vector>

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const vector<int>& vec, int target) override {
        numberComparisons = 0;
        for (size_t i = 0; i < vec.size(); ++i) {
            numberComparisons++;
            if (vec[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> numbers = {3, 5, 7, 9, 11, 13};
    LinearSearch searchAlgo;
    int target = 9;
    int result = searchAlgo.search(numbers, target);
    searchAlgo.displaySearchResults(cout, result, target);
    return 0;
}
