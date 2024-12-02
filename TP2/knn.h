#pragma once

#include "TimeSeriesDataset.h"
#include <string>
#include <vector>
using namespace std;

class KNN {
private:
    int k;
    string similarityMeasure;

public:
    KNN(int k, const string& similarityMeasure);

    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& groundTruth);
};
