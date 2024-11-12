#include  "energyCard.h"
#include <iostream>

using namespace std;

EnergyCard::EnergyCard(const string energyType)
: energyType(energyType)
{
    this->cardName="Energy";
}

void EnergyCard::displayInfo() const{
    cout << "Card Name:" << cardName << endl;
    cout << "Energy Type:" << energyType << endl;
}
