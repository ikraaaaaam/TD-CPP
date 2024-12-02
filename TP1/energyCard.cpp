#include "energyCard.h"
#include <iostream>
using namespace std;

EnergyCard::EnergyCard(const string& type) : Card("Energy"), energyType(type) {}

void EnergyCard::displayInfo() const {
    cout << "Energy Card - Type: " << energyType << endl;
}

const string& EnergyCard::getEnergyType() const {
    return energyType;
}
