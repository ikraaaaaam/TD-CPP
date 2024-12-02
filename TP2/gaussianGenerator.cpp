#include "GaussianGenerator.h"
#include <random>

GaussianGenerator::GaussianGenerator(double mean, double stddev) : mean(mean), stddev(stddev) {}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> series(size);
    default_random_engine generator(seed);
    normal_distribution<double> distribution(mean, stddev);

    for (int i = 0; i < size; ++i) {
        series[i] = distribution(generator);
    }

    return series;
}
