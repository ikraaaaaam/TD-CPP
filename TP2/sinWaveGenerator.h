#pragma once

#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;

public:
    SinWaveGenerator(double amplitude, double frequency, double phase);
    vector<double> generateTimeSeries(int size) override;
};
