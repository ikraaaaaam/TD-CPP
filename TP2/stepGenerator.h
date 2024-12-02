#pragma once

#include "TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    vector<double> generateTimeSeries(int size) override;
};
