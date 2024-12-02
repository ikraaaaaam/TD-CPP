#include "SinWaveGenerator.h"
#include <cmath>

SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase)
    : amplitude(amplitude), frequency(frequency), phase(phase) {}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> series(size);

    for (int i = 0; i < size; ++i) {
        series[i] = amplitude * sin(frequency * i + phase);
    }

    return series;
}
