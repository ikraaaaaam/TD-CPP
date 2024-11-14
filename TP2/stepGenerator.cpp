#include <stepGenerator.h>
#include <cstdlib>

stepGenerator::stepGenerator():TimeSeriesGenerator(){}
vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series(size);
    series[0] = 0; 
    for (int i = 1; i < size; ++i) {
        if (rand() % 2) {
            series[i] = series[i - 1]; 
        } else {
            series[i] = rand() % 101; 
        }
    }
    return series;
}