#pragma once 

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator{
private:
    double A;
    double w;
    double phase;
public:
    SinWaveGenerator();
    SinWaveGenerator(double A, double w, double phase);
    vector<double> generateTimeSeries(int size) override;
}