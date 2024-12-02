#pragma once

#include <vector>
using namespace std;

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual ~TimeSeriesGenerator() = default;

    virtual vector<double> generateTimeSeries(int size) = 0;
    static void printTimeSeries(const vector<double>& series);
};
