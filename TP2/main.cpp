#include "knn.h"
#include "TimeSeriesGenerator.h"
#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "TimeSeriesDataset.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    GaussianGenerator gaussianGen(0.0, 1.0);
    SinWaveGenerator sinWaveGen(1.0, 0.1, 0.0);
    StepGenerator stepGen;

    TimeSeriesDataset trainData(false, true);
    TimeSeriesDataset testData(false, false);

    trainData.addTimeSeries(gaussianGen.generateTimeSeries(10), 0);
    trainData.addTimeSeries(sinWaveGen.generateTimeSeries(10), 1);
    trainData.addTimeSeries(stepGen.generateTimeSeries(10), 2);

    testData.addTimeSeries(gaussianGen.generateTimeSeries(10), 0);
    testData.addTimeSeries(sinWaveGen.generateTimeSeries(10), 1);
    testData.addTimeSeries(stepGen.generateTimeSeries(10), 2);

    KNN knn(1, "euclidean_distance");
    vector<int> groundTruth = {0, 1, 2};
    double accuracy = knn.evaluate(trainData, testData, groundTruth);

    cout << "Accuracy: " << accuracy << endl;

    return 0;
}
