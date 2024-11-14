#include "SinWaveGenerator.h"
#include <cmath>

using namespace std;

SinWaveGenerator::SinWaveGenerator(double A, double w, double phase) : TimeSeriesGenerator(), A(A), w(w), phase(phase) {}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> series(size);
    for (int i = 0; i < size; ++i) {
        series[i] = amplitude * sin(frequency * i + phase);
    }
    return series;