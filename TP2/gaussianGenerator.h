#pragma once

#include "TimeSeriesGenerator.h"

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;

public:
    GaussianGenerator(double mean, double stddev);
    vector<double> generateTimeSeries(int size) override;
};
