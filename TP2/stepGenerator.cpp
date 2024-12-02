#include "StepGenerator.h"
#include <random>

StepGenerator::StepGenerator() {}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series(size);
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 1);

    series[0] = 0; // Initial value

    for (int i = 1; i < size; ++i) {
        if (distribution(generator)) {
            series[i] = series[i - 1];
        } else {
            series[i] = rand() % 101; // Random value between 0 and 100
        }
    }

    return series;
}
