#include "gaussianGenerator.h"

using namespace std;

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), stddev(1.0) {}


GaussianGenerator::GaussianGenerator(int s, double m, double sd) 
    : TimeSeriesGenerator(s), mean(m), stddev(sd) {}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.reserve(size);

    
    mt19937 generator(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < size; i += 2) {
        double u1 = distribution(generator);
        double u2 = distribution(generator);

        double z0 = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);
        double z1 = sqrt(-2.0 * log(u1)) * sin(2 * M_PI * u2);

        series.push_back(mean + z0 * stddev);
        if (i + 1 < size) {
            series.push_back(mean + z1 * stddev);
        }
    }
    return series;
}