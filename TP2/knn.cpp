#include "knn.h"
#include <algorithm>
#include <cmath>
using namespace std;

KNN::KNN(int k, const string& similarityMeasure)
    : k(k), similarityMeasure(similarityMeasure) {}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& groundTruth) {
    int correct = 0;

    const auto& trainDataVec = trainData.getData();
    const auto& testDataVec = testData.getData();
    const auto& trainLabels = trainData.getLabels();

    for (size_t i = 0; i < testDataVec.size(); ++i) {
        vector<pair<double, int>> distances;

        for (size_t j = 0; j < trainDataVec.size(); ++j) {
            double distance = 0.0;

            if (similarityMeasure == "euclidean_distance") {
                for (size_t k = 0; k < testDataVec[i].size(); ++k) {
                    distance += pow(testDataVec[i][k] - trainDataVec[j][k], 2);
                }
                distance = sqrt(distance);
            }
            distances.emplace_back(distance, trainLabels[j]);
        }

        sort(distances.begin(), distances.end());
        int predictedLabel = distances.front().second;

        if (predictedLabel == groundTruth[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / testDataVec.size();
}
