#pragma once
#include <vector>
using namespace std;

class TimeSeriesDataset {
private:
    vector<vector<double>> data;
    vector<int> labels;
    bool znormalize; // Manquant dans votre déclaration
    bool isTrain;    // Manquant dans votre déclaration

public:
    TimeSeriesDataset(bool znormalize, bool isTrain);

    void addTimeSeries(const vector<double>& series, int label);
    void normalizeSeries();

    // Accesseurs publics
    const vector<vector<double>>& getData() const {
        return data;
    }

    const vector<int>& getLabels() const {
        return labels;
    }
};
