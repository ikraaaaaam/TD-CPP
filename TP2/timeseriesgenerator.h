#pragma once 

#include <vector>
using namespace std;

class TimeSeriesGenerator{
private:
    int seed;
public:
    TimeSeriesGenerator() : seed(0){
    TimeSeriesGenerator(int s) : seed(s){}
    virtual vector<double> generateTimeSeries(int)=0;
    virtual void printTimeSeries(const vector<double> series);
    }
}