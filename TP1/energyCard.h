#pragma once
#include <string>
using namespace std;

class EnergyCard : public Card{
protected:
    string energyType;

public:
    EnergyCard(string energyType);
}