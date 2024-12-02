#include "TimeSeriesDataset.h"
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain) {}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    data.push_back(series);
    labels.push_back(label);

    if (znormalize) {
        normalizeSeries();
    }
}

void TimeSeriesDataset::normalizeSeries() {
    for (auto& series : data) {
        double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();
        double sq_sum = inner_product(series.begin(), series.end(), series.begin(), 0.0);
        double stdev = sqrt(sq_sum / series.size() - mean * mean);

        for (auto& value : series) {
            value = (value - mean) / stdev;
        }
    }
}
