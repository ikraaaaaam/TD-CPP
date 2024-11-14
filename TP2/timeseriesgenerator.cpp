#include "timeseriesgenerator.h"

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0){}
TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s){}

void TimeSeriesGenerator::printTimeSeries(const vector<double> series){
    for(double value:series){
        cout << value << endl;
    }
}