#pragma once
#include "timeseriesgenerator.h"
#include <vector>

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;
public:
    GaussianGenerator();
    GaussianGenerator(int seed, double mean, double stddev):TimeSeriesGenerator(s), mean(m), stddev(sd){};
    vector<double> generateTimeSeries(int size);

}